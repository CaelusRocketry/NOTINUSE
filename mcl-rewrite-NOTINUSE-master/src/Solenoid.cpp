#include <string>
#include <sstream>

#include "Solenoid.hpp"
#include "ArduinoJson.h"

#ifndef DESKTOP
#include <Arduino.h>
#endif

namespace caelus
{
	using std::string;

	Solenoid::Solenoid(int pin) : pin(pin) {}

	void Solenoid::actuate(SolenoidActuationType type, SolenoidActuationPriority priority)
	{
		this->actuationType = type;
		switch (type)
		{
		case SolenoidActuationType::OPEN_VENT:
			this->state = SolenoidState::OPEN;

#ifndef DESKTOP
			digitalWrite(pin, HIGH);
#endif
			break;

		case SolenoidActuationType::CLOSE_VENT:
			this->state = SolenoidState::CLOSED;
#ifndef DESKTOP
			digitalWrite(pin, LOW);
#endif
		}
	}

	SolenoidState Solenoid::getState() const
	{
		return state;
	}

	SolenoidActuationType Solenoid::getActuationType() const
	{
		return actuationType;
	}

	SolenoidActuationPriority Solenoid::getActuationPriority() const
	{
		return actuationPriority;
	}

	string Solenoid::toJSONString() const
	{
		auto object = toJson();

		string out;
		serializeJson(object, out);
		return out;
	}

	bool Solenoid::isOpen() const
	{
		return state == SolenoidState::OPEN;
	}

	JsonObject Solenoid::toJson() const
	{
		ArduinoJson::JsonObject object;

		object["state"] = toString(state);
		object["actuationType"] = toString(actuationType);
		object["actuationPriority"] = toString(actuationPriority);

		return object;
	}
}