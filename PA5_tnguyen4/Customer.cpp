#include "Customer.h"

Customer::Customer(double arrivalTime) {
	this->arrivalTime = arrivalTime;
	this->serviceStartTime = NULL_TIME;
	this->endTime = NULL_TIME;
	this->isServed = false;
}

void Customer::renew() {
	this->serviceStartTime = NULL_TIME;
	this->endTime = NULL_TIME;
	this->isServed = false;
}

double Customer::getArrTime() {
	return this->arrivalTime;
}

bool Customer::isDone() {
	return isServed;
}

void Customer::setSerStartTime(double t) {
	this->serviceStartTime = t;
}

void Customer::setEndTime(double t) {
	this->isServed = true;
	this->endTime = t;
}

double Customer::getAllTime() {
	return endTime - arrivalTime;
}

Customer::~Customer() {
	// nothing needed, since no pointer in fields
}
