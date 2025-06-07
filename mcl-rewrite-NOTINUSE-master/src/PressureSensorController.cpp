#include "PressureSensorController.hpp"

#include <iostream>
#include <vector>

#include "Debug.hpp"

namespace caelus
{

	PressureSensorController::PressureSensorController(Launch *launch, Store *store) : launch(launch), store(store)
	{
		debug("pressure-control", "initialized");
	}

	void PressureSensorController::begin()
	{
		debug("pressure-control", "beginning");

		// if we're using the PT-2 sensor in this test
		if (store->hasPressureSensor("PT-2"))
		{
			this->pressureReliefValveMap.push_back(std::make_pair("PT-2", "PRESSURE_RELIEF"));
		}

		for (const auto &match : this->pressureReliefValveMap)
		{
			auto pressureSensor = match.first;
			auto pressureReliefValve = match.second;

			if (!store->hasPressureSensor(pressureSensor))
			{
				debug("pressure-control", "sensor at " + pressureSensor + " not registered");
			}

			if (!store->hasSolenoid(pressureReliefValve))
			{
				debug("pressure-control", "pressure relief valve at " + pressureReliefValve + " not registered");
			}
		}
	}

	void PressureSensorController::execute()
	{
		checkPressure();
	}

	void PressureSensorController::checkPressure()
	{
		for (pair<string, string> match : this->pressureReliefValveMap)
		{
			auto pressureSensorID = match.first;
			auto pressureReliefValveID = match.second;

			auto pressureSensor = store->getPressureSensor(pressureSensorID);
			auto pressureReliefValue = store->getSolenoid(pressureReliefValveID);

			auto pressureMeasurement = pressureSensor->getMostRecentMeasurement();

			if (pressureMeasurement.value > pressureSensor->getSensorMeasurementRanges(launch->getStage()).safe.upper)
			{
				if (!pressureReliefValue->isOpen())
				{
					launch->enqueueSolenoidActuation(
							pressureReliefValveID,
							SolenoidActuationPriority::PI_PRIORITY,
							SolenoidActuationType::OPEN_VENT);
				}
			}
			else if (pressureSensor->getStatus() == SensorStatus::SAFE)
			{
				if (pressureReliefValue->isOpen())
				{
					launch->enqueueSolenoidActuation(
							pressureReliefValveID,
							SolenoidActuationPriority::PI_PRIORITY,
							SolenoidActuationType::OPEN_VENT);
				}
			}
		}
	}

}