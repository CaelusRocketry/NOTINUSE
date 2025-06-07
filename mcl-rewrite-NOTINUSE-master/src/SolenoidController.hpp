#ifndef SOLENOID_CONTROLLER_HPP
#define SOLENOID_CONTROLLER_HPP

#include <vector>
#include <string>

namespace caelus
{
	class SolenoidController;
};

#include "Launch.hpp"

namespace caelus
{

	using std::pair;
	using std::string;
	using std::vector;

	class SolenoidController
	{
	private:
		vector<pair<string, string>> valves;

		Launch *launch;

		// all time is calculated in milliseconds
		long sendInterval;
		long double lastSendTime = 0;
		bool aborted = false;

		void sendSolenoidData();
		void abort();
		void undoAbort();
		void checkAbort();

	public:
		SolenoidController(Launch *launch, long sendInterval);
		void begin();
		void execute();
	};

}

#endif //FLIGHT_VALVECONTROL_HPP
