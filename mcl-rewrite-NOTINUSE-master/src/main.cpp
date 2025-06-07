#include "Launch.hpp"

int main() {
	caelus::Config config;
	caelus::Launch launch(config);

	launch.loop();
}