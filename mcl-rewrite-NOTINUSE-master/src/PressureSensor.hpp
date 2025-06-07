#ifndef PRESSURE_SENSOR_HPP
#define PRESSURE_SENSOR_HPP

#include <vector>

namespace caelus
{
	class PressureSensor;
};

#include "Enums.hpp"
#include "Sensor.hpp"
#include "SensorStructs.hpp"

namespace caelus
{
	using std::pair;
	using std::vector;

	class PressureSensor : public Sensor<double>
	{
	private:
		PressureSensorConfig config;
		SensorStatus status;
		vector<SensorMeasurementRanges> stageMeasurementRangesByStage;
		int pin;

		void checkBoundaries() const;

	public:
		PressureSensor(PressureSensorConfig config);

		SensorMeasurement<double> readMeasurement() override;

		const SensorMeasurementRanges getSensorMeasurementRanges(Stage stage) const;
	};
}

#endif
