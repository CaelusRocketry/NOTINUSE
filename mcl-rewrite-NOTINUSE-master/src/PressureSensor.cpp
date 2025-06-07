#include "PressureSensor.hpp"

#ifndef DESKTOP
#include "Arduino.h"
#include "Util.hpp"
#endif

namespace caelus
{
	float mapValue(float x, float in_min, float in_max, float out_min, float out_max)
	{
		float in_width = in_max - in_min;
		float out_width = out_max - out_min;
		float factor = out_width / in_width;
		return (x - in_min) * factor + out_min;
	}

	PressureSensor::PressureSensor(PressureSensorConfig config) : config(config)
	{
	}

	SensorMeasurement<double> PressureSensor::readMeasurement()
	{
#ifdef DESKTOP
		return SensorMeasurement<double>{0, 0};
#else
		float pwmVal = analogRead(pin);
		float voltage = mapValue(pwmVal, 147, 1024, 0.5, 4.5) + 0.0100;
		float psi = mapValue(voltage, 0.5, 4.5, 15, 1000) - 15;
		print(toString(psi) + " " + toString(voltage) + " " + toString(pwmVal));
		return SensorMeasurement<double>{0, psi};
#endif
	}

	const SensorMeasurementRanges PressureSensor::getSensorMeasurementRanges(Stage stage) const
	{
		return stageMeasurementRangesByStage[static_cast<int>(stage)];
	}
}