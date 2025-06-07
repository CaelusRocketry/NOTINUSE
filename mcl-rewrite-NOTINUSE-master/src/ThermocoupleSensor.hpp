#include "Sensor.hpp"

#ifndef DESKTOP
#include <Adafruit_MAX31856.h>
#endif

namespace caelus
{
	typedef struct ThermocoupleSensorConfig
	{
		int pin1, pin2, pin3, pin4;
	} ThermocoupleSensorConfig;

	class ThermocoupleSensor : Sensor<double>
	{
#ifndef DESKTOP
	private:
		Adafruit_MAX31856 native;
#endif
	public:
		ThermocoupleSensor(const ThermocoupleSensorConfig &config);
		SensorMeasurement<double> readMeasurement() override;
	};
}