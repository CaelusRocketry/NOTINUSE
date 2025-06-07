#include <iostream>

#include "ArduinoJson.h"

#include "Launch.hpp"
#include "StageController.hpp"
#include "Util.hpp"

namespace caelus
{

	StageController::StageController(Launch *launch) : launch(launch)
	{
		lastStageStartTime = now();
	}

	void StageController::execute()
	{
		int status = calculateStageCompletionProgress();
		launch->setStageCompletionProgress(status);

		if (launch->isProgressPending())
		{
			this->progress();
			launch->setProgressPending(false);
		}
		else if (status >= 100)
		{
			double timeSinceLastProgressionRequest = now() - lastProgressionRequestTime;
			if (lastProgressionRequestTime == 0 || timeSinceLastProgressionRequest > requestInterval)
			{
				sendProgressionRequest();
				lastProgressionRequestTime = now();
			}
		}

		actuatePressureRelief();
		sendStageData();
	}

	int StageController::calculateStageCompletionProgress() const
	{
		switch (launch->getStage())
		{
		case Stage::WAITING:
			return 100;
		case Stage::PRESSURIZATION:
		{
			auto PT_2 = launch->getStore()->getPressureSensor("PT-2");
			if (PT_2 != nullptr)
			{
				auto measurement = PT_2->getMostRecentMeasurement().value;
				return (int)(measurement / 4.9);
			}
			else
			{
				return 100;
			}
		}

		case Stage::AUTOSEQUENCE:
		{
			SolenoidActuationType mainPropellantValveActuation = launch->getStore()->getSolenoid("main_propellant_value")->getActuationType();

			if (mainPropellantValveActuation == SolenoidActuationType::OPEN_VENT)
			{
				return 100;
			}
			else
			{
				auto elapsedTime = now() - this->lastStageStartTime;
				return (int)(100 * elapsedTime / AUTOSEQUENCE_DELAY);
			}
		}

		case Stage::POSTBURN:
		{
			double pressure = launch->getStore()->getPressureSensor("PT-2")->getMostRecentMeasurement().value;
			double inv = (pressure - 20.0) / 5.0; // Assuming that "depressurization" means 20psi
			double progress = min(100.0, 100.0 - inv);

			return (int)max(0.0, progress); //  makes sure that progress isn't negative
		}
		}

		return 0;
	}

	void StageController::sendProgressionRequest()
	{
		launch->log()->stageProgressionRequest(launch->getStage(), nextStage(launch->getStage()));
	}

	void StageController::sendStageData()
	{
		if (lastSendTime == 0 || (now() - lastSendTime) > sendInterval)
		{
			ArduinoJson::JsonObject object;

			object["header"] = "stage_data";
			object["stage"] = toString(launch->getStage());
			object["status"] = calculateStageCompletionProgress();

			string out;
			serializeJson(object, out);
			launch->log()->sendStageData(out);

			this->lastSendTime = now();
		}
	}

	void StageController::progress()
	{
		int status = calculateStageCompletionProgress();
		if (status == 100)
		{
			launch->setStage(nextStage(launch->getStage()));
			lastSendTime = 0;
			lastProgressionRequestTime = 0;
			launch->setStageCompletionProgress(calculateStageCompletionProgress());
			lastStageStartTime = now();
		}
	}

	void StageController::actuatePressureRelief()
	{
		switch (launch->getStage())
		{
		//TODO: make this actuate valves based on the current stage
		case Stage::WAITING:
		{
			auto pressureReliefValve = launch->getStore()->getSolenoid("pressure_relief");
			if (pressureReliefValve->getActuationType() != SolenoidActuationType::CLOSE_VENT)
			{
				launch->enqueueSolenoidActuation(
						"pressure_relief",
						SolenoidActuationPriority::PI_PRIORITY,
						SolenoidActuationType::CLOSE_VENT);
			}

			auto mainPropellantValve = launch->getStore()->getSolenoid("main_propellant_valve");
			if (mainPropellantValve->getActuationType() != SolenoidActuationType::CLOSE_VENT)
			{
				launch->enqueueSolenoidActuation(
						"main_propellant_valve",
						SolenoidActuationPriority::PI_PRIORITY,
						SolenoidActuationType::CLOSE_VENT);
			}
		}

		case Stage::PRESSURIZATION:
			break;

		case Stage::AUTOSEQUENCE:
		{
			auto elapsedTime = now() - lastStageStartTime;

			auto mainPropellantValve = launch->getStore()->getSolenoid("main_propellant_valve");
			bool isNotOpen = mainPropellantValve->getActuationType() != SolenoidActuationType::OPEN_VENT;
			bool readyToStart = elapsedTime > AUTOSEQUENCE_DELAY;
			if (isNotOpen && readyToStart)
			{
				launch->enqueueSolenoidActuation(
						"main_propellant_valve",
						SolenoidActuationPriority::PI_PRIORITY,
						SolenoidActuationType::OPEN_VENT);
			}
		}

		case Stage::POSTBURN:
		{
			if (!actuatedPostburn)
			{
				launch->enqueueSolenoidActuation(
						"main_propellant_valve",
						SolenoidActuationPriority::PI_PRIORITY,
						SolenoidActuationType::OPEN_VENT);

				launch->enqueueSolenoidActuation(
						"pressure_relief",
						SolenoidActuationPriority::PI_PRIORITY,
						SolenoidActuationType::OPEN_VENT);

				actuatedPostburn = true;
			}
		}
		}
	}

}