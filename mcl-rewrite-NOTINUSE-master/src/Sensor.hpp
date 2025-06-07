#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <vector>

namespace caelus
{
	template <typename T>
	class Sensor;
};

#include "Enums.hpp"
#include "SensorStructs.hpp"

namespace caelus
{
	using std::pair;
	using std::vector;

	// Because this is a template class, the implementation MUST be defined in the header file.
	template <typename T>
	class Sensor
	{
	private:
		std::vector<SensorMeasurement<T>> measurements;
		long long lastMeasurementTime = -1;
		PressureSensorConfig config;
		SensorStatus status;
		vector<SensorMeasurementRanges> stageMeasurementRangesByStage;

	public:
		/**
			 * Returns true if there is a measurement.
			 */
		bool hasMeasurement() const noexcept
		{
			return measurements.size() > 0;
		}

		virtual SensorMeasurement<T> readMeasurement() = 0;

		/**
			 * Adds a measurement to the measurements vector.
			 */
		void addMeasurement(SensorMeasurement<T> measurement)
		{
			measurements.push_back(measurement);
		}

		/**
			 * Returns the most recent measurement. If there is none, it will return a SensorMeasurement with a timestamp of -1, and a value of 0.
			 */
		SensorMeasurement<T> getMostRecentMeasurement() const
		{
			return measurements.at(measurements.size() - 1);
		}

		/**
			 * Returns a vector, in sorted order by timestamp, of the measurement history of the sensor.
			 */
		const vector<SensorMeasurement<T>> &getMeasurementHistory() const noexcept
		{
			return measurements;
		}

		SensorStatus getStatus() const
		{
			return status;
		}
	};
}

#endif
