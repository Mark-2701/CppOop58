#include "Laptop.h"
#include <format>

std::string Laptop::getHardware() const {
	return hardware;
}

void Laptop::setHardware(std::string hardware) {
	this->hardware = hardware;
}

std::string Laptop::to_string() {
	return std::format("{} {} hrn, {} ({} W)",
		get_Name(),
		get_Price(),
		hardware,
		getPower());
}