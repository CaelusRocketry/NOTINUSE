#ifndef SENSOR_STRUCTS_HPP
#define SENSOR_STRUCTS_HPP

#include <vector>

namespace caelus
{
	using std::vector;

	typedef struct KalmanParameters
	{
		double process_variance, measurement_variance, kalman_value;
	} KalmanParameters;

	template <typename T>
	struct SensorMeasurement
	{
		long long timestamp;
		T value;
		SensorMeasurement(long long timestamp, T value): timestamp(timestamp), value(value) {

		}
	};

	typedef struct SensorMeasurementRange
	{
		double lower;
		double upper;
	} SensorMeasurementRange;

	typedef struct SensorMeasurementRanges
	{
		SensorMeasurementRange safe, warn, actuate, abort;
	} SensorMeasurementRanges;

	typedef struct PressureSensorConfig
	{
		KalmanParameters kalmanParameters;
		vector<SensorMeasurementRanges> stageMeasurementRangesByStage;
		vector<int> pins;
	} PressureSensorConfig;
}

#endif