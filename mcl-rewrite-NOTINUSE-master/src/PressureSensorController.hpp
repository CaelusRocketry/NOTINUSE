#ifndef PRESSURE_SENSOR_CONTROLLER_HPP
#define PRESSURE_SENSOR_CONTROLLER_HPP

#include <map>
#include <vector>

namespace caelus
{
	class PressureSensorController;
}

#include "Launch.hpp"
#include "Store.hpp"

namespace caelus
{
	using std::basic_string;
	using std::pair;
	using std::string;
	using std::vector;

	class PressureSensorController
	{
	private:
		vector<basic_string<char>> activateStages;
		vector<pair<string, string>> pressureReliefValveMap;

		Launch *launch;
		Store *store;

		void checkPressure();

	public:
		PressureSensorController(Launch *launch, Store *store);
		void execute();
		void begin();
	};
}

#endif