#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <vector>

#ifdef TEENSY
    // #include <SD_ts.h>
    #include <SD.h>
#endif

#include "ArduinoJson.h"

namespace caelus {

using std::string;

enum class LogPriority {
	INFO = 4,
	DEBUG = 3,
	WARN = 2,
	CRIT = 1
};

// Log class stores messages to be sent to and from ground and flight station
class Log {
private:
    string header;
    string message;
    long double timestamp;
    string _cachedString;

		string _toStringHidden() const;

public:
    Log();

    Log(const string& header, const string& message, long double timestamp, bool save = true):
			header(header),
			message(message),
			timestamp(timestamp) {
			_cachedString = _toStringHidden();

			if (save) {
				this->save();
			}
    }

		string toString() const;
		ArduinoJson::JsonObject toJson() const;
		static Log fromJson(void *json);

    void save(const string& filename = "black_box.txt") const;

    Log copy();
    string getHeader() const;
    string getMessage() const;
    long double getTimestamp() const;
};

}


#endif //FLIGHT_LOG_HPP
