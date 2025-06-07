#include "Launch.hpp"

#include <iostream>

#include "Debug.hpp"
#include "Util.hpp"

namespace caelus
{
	void Launch::readSensorMeasurements()
	{
		debug("launch", "reading sensor measurements");

		for (const auto &entry : store->getPressureSensors())
		{
			auto sensor = entry.second;
			auto measurement = sensor.readMeasurement();
			sensor.addMeasurement(measurement);
		}

		// Add thermocouple and load cell
	}
}
