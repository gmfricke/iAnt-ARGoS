#include "Controller.h"

Controller::Controller() :
	steeringActuator(NULL),
	proximitySensor(NULL),
	groundSensor(NULL),
	lightSensor(NULL),
	RNG(NULL)
{}

Controller::~Controller() {
}

void Controller::Init(TConfigurationNode& node) {
}

void Controller::ControlStep() {
}

void Controller::Reset() {
}

void Controller::Destroy() {
}