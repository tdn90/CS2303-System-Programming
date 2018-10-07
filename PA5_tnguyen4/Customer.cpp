
#include "Customer.h"

Customer::Customer(double arrivalTime) {
	this->arrivalTime = arrivalTime;
	this->serviceStartTime = -1;
	this->endTime = -1;
	this->isServed = false;
}

bool Customer::isDone() {
	return isServed;
}

Customer::~Customer() {
	// nothing needed, since no pointer in fields
}
