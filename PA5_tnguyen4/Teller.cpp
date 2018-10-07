#include "Teller.h"

Teller::Teller(double idleTime) {
	this->idleTime = rand() % MAX_IDLE_TIME;
	this->serviceTime = 0;
	this->inService = false;
	this->onBreak = false;
}

bool Teller::isAvailable() {
	return !onBreak && !inService;
}

bool Teller::justServed() {
	return inService;
}

bool Teller::justIdled() {
	return onBreak;
}

Teller::~Teller() {
	// nothing to do
}
