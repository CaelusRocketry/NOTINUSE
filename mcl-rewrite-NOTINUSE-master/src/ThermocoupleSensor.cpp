#include "ThermocoupleSensor.hpp"

#include "Util.hpp" // now()

namespace caelus
{
	ThermocoupleSensor::ThermocoupleSensor(const ThermocoupleSensorConfig &config)
#ifndef DESKTOP
			// Initialize the native driver
			: native(Adafruit_MAX31856(config.pin1, config.pin2, config.pin3, config.pin4))
#endif
	{
#ifndef DESKTOP
		// Begin collecting readings
		native.begin();
#endif
	}

	SensorMeasurement<double> ThermocoupleSensor::readMeasurement()
	{
#ifdef DESKTOP
		return SensorMeasurement<double>{0, 0};
#else
		float temperature = native.readThermocoupleTemperature();
		return SensorMeasurement<double>{now(), temperature};
#endif
	}
}
