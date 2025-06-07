#include "SolenoidController.hpp"

#include <iostream>
#include <sstream>

#include "ArduinoJson.h"

#include "Debug.hpp"
#include "Util.hpp"

namespace caelus
{

	SolenoidController::SolenoidController(Launch *launch, long sendInterval) : launch(launch), sendInterval(sendInterval)
	{
		// config send interval in seconds, convert to milliseconds
		this->lastSendTime = 0;
		this->aborted = false;
	}

	void SolenoidController::begin()
	{
		launch->log()->controllerInitialized("solenoid");
	}

	void SolenoidController::execute()
	{
		checkAbort();
		auto now = caelus::now();

		if (lastSendTime == 0 || now > lastSendTime + sendInterval)
		{
			sendSolenoidData();
			lastSendTime = now;
		}
	}

	void SolenoidController::sendSolenoidData()
	{
		auto store = launch->getStore();

		ArduinoJson::JsonObject object;
		ArduinoJson::JsonArray valves;

		for (const auto &entry : store->getSolenoids())
		{
			string id = entry.first;
			const Solenoid &solenoid = entry.second;

			valves.add(solenoid.toJson());
		}

		object["valves"] = valves;
		object["timestamp"] = now() / 1000;

		string out;
		serializeJson(object, out);

		launch->log()->sendValveData(out);
	}

	void SolenoidController::abort()
	{
		debug("launch", "aborting");

		for (const auto &entry : launch->getStore()->getSolenoids())
		{
			string id = entry.first;
			Solenoid solenoid = entry.second;

			auto actuationType = solenoid.getActuationType();
			auto actuationPriority = solenoid.getActuationPriority();

			bool isNotOpenVent = actuationType != SolenoidActuationType::OPEN_VENT;
			bool isNotAbortPriority = actuationPriority != SolenoidActuationPriority::ABORT_PRIORITY;

			if (isNotOpenVent || isNotAbortPriority)
			{
				launch->enqueueSolenoidActuation(
						id,
						SolenoidActuationPriority::ABORT_PRIORITY,
						SolenoidActuationType::OPEN_VENT);
			}
		}

		this->aborted = true;
	}

	// Set the actuation type to NONE, with ABORT_PRIORITY priority
	void SolenoidController::undoAbort()
	{
		debug("launch", "undoing abort");

		for (const auto &entry : launch->getStore()->getSolenoids())
		{
			string id = entry.first;
			Solenoid solenoid = entry.second;

			if (solenoid.getActuationPriority() == SolenoidActuationPriority::ABORT_PRIORITY)
			{
				launch->enqueueSolenoidActuation(
						id,
						SolenoidActuationPriority::ABORT_PRIORITY,
						SolenoidActuationType::NONE);
			}
		}

		this->aborted = false;
	}

	void SolenoidController::checkAbort()
	{
		if (launch->isSoftAborting() && !aborted)
		{
			abort();
		}
		else if (!launch->isSoftAborting() && aborted)
		{
			undoAbort();
		}
	}

}