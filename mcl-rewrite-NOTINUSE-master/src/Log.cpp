#include "Log.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include "ArduinoJson.h"

#include "Debug.hpp"

namespace caelus
{

	string Log::_toStringHidden() const
	{
		ArduinoJson::JsonObject object;

		object["header"] = header;
		object["timestamp"] = timestamp;
		object["message"] = message;

		string result;
		serializeJson(object, result);

		return result;
	}

	string Log::toString() const
	{
		return _cachedString;
	}

	// Log string to black_box.txt
	void Log::save(const string &filename) const
	{
#ifdef DESKTOP
		std::ofstream savefile(filename);
		savefile << toString() << '\n';
		savefile.close();
#endif // DESKTOP

#ifdef TEENSY
		debug("logger", "writing to sd card");
		const char *saveFileName = "blackbox.txt";

		File savefile = SD.open(saveFileName, FILE_WRITE);
		if (savefile)
		{
			// it opened OK
			debug("logger", "saving file");

			savefile.println(toString().c_str());
			savefile.close();

			debug("logger", "save file done");
		}
		else
		{
			debug("logger", "save file error");
		}
#endif // TEENSY
	}

	Log Log::copy()
	{
		// Create a copy of the log
		return Log(header, message, timestamp, false);
	}

	string Log::getHeader() const
	{
		return header;
	}

	string Log::getMessage() const
	{
		return message;
	}

	long double Log::getTimestamp() const
	{
		return timestamp;
	}

	JsonObject Log::toJson() const
	{
		JsonObject value;

		value["header"] = header;
		value["message"] = message;
		value["timestamp"] = timestamp;

		return value;
	}

}
