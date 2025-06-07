#ifndef PACKET_HPP
#define PACKET_HPP

#include <string>
#include <vector>

#include "Log.hpp"

namespace caelus
{

	using std::string;
	using std::vector;

	// Packet class groups together logs of similar priority
	class Packet
	{
	private:
	public:
		LogPriority priority;
		long double timestamp;
		vector<Log> logs;

		Packet() = default;

		explicit Packet(LogPriority priority, long double timestamp, vector<Log> logs) : priority(priority),
																																										 timestamp(timestamp),
																																										 logs(logs) {}

		explicit Packet(LogPriority priority, long double timestamp) : priority(priority),
																																	 timestamp(timestamp) {}

		void add(const Log &log);
		vector<Log> getLogs();

		string toString();

		struct compareTo
		{
			bool operator()(const Packet &lhs, const Packet &rhs)
			{
				if (lhs.priority != rhs.priority)
				{
					return lhs.priority < rhs.priority;
				}
				else
				{
					return lhs.timestamp < rhs.timestamp;
				}
			}
		};
	};

}

#endif //FLIGHT_PACKET_HPP
