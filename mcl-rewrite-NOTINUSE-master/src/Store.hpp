#ifndef SENSOR_STORE_HPP
#define SENSOR_STORE_HPP

#include <map>

namespace caelus
{
	class Store;
}

#include "Config.hpp"
#include "PressureSensor.hpp"
#include "Solenoid.hpp"

namespace caelus
{

	using std::map;
	using std::string;

	class Store
	{
	private:
		map<string, Solenoid> solenoids;
		map<string, PressureSensor> pressureSensors;

	public:
		Store(const Config &config);

		PressureSensor *getPressureSensor(string id);
		Solenoid *getSolenoid(string id);
		const map<string, PressureSensor> getPressureSensors() const;
		const map<string, Solenoid> getSolenoids() const;

		bool hasPressureSensor(string id) const;
		bool hasSolenoid(string id) const;
	};

}

#endif