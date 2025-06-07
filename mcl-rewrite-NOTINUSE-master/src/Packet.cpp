#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Packet.hpp"
#include "Util.hpp" // sc
#include "ArduinoJson.h"

namespace caelus {

using std::string;
using std::stringstream;
using std::vector;

string Packet::toString() {
    ArduinoJson::JsonObject object;

    object["priority"] = i(priority);
    object["timestamp"] = timestamp;

    ArduinoJson::JsonArray logArray;
    for (const auto& log : logs) {
        logArray.add(log.toJson());
    }

    object["logs"] = logArray;

    string out;
    serializeJson(object, out);
    return out;
}

void Packet::add(const Log& log) {
    logs.push_back(log);
}

vector<Log> Packet::getLogs() {
    return this->logs;
}

}
