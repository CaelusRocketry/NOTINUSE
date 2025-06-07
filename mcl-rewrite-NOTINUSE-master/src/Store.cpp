#include "Store.hpp"

namespace caelus {

Store::Store(const Config& config) {
	for (const auto& entry : config.sensors.pressureSensors) {
		string id = entry.first;
		auto sensorConfig = entry.second;
		PressureSensor sensor(sensorConfig);
		this->pressureSensors.insert({id, sensor});
	}

	for (const auto& entry : config.valves.solenoids) {
		string id = entry.first;
		auto solenoid = entry.second;
		this->solenoids.insert({id, solenoid});
	}
}

// MUSTFIX
PressureSensor *Store::getPressureSensor(string id) {
	auto ptr = pressureSensors.find(id);
	if (ptr == pressureSensors.end()) {
		return nullptr;
	} else {
		return &(ptr->second);
	}
}

Solenoid *Store::getSolenoid(string id) {
	auto ptr = solenoids.find(id);
	if (ptr == solenoids.end()) {
		return nullptr;
	} else {
		return &(ptr->second);
	}
}

const map<string, PressureSensor> Store::getPressureSensors() const {
	return pressureSensors;
}

const map<string, Solenoid> Store::getSolenoids() const {
	return solenoids;
}

bool Store::hasPressureSensor(string id) const {
	return pressureSensors.find(id) != pressureSensors.end();
}

bool Store::hasSolenoid(string id) const {
	return solenoids.find(id) != solenoids.end();
}

}