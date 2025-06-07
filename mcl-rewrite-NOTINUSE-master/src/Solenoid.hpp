#ifndef SOLENOID_HPP
#define SOLENOID_HPP

#include "ArduinoJson.h"

#include "Enums.hpp"

namespace caelus {
	class Solenoid {
		private:
			SolenoidState state;
			SolenoidActuationType actuationType;
			SolenoidActuationPriority actuationPriority;
			int pin;

		public:
			Solenoid(int pin);

			void actuate(SolenoidActuationType type, SolenoidActuationPriority priority);

			SolenoidState getState() const;
			SolenoidActuationType getActuationType() const;
			SolenoidActuationPriority getActuationPriority() const;
			string toJSONString() const;
			JsonObject toJson() const;

			bool isOpen() const;
	};
}

#endif