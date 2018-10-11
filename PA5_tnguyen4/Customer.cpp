/**
 * Customer.cpp
 * @author: Dung (Kevin) Nguyen
 */

#include "Customer.h"

/**
 * Constructor for Customer
 * @param arrivalTime The time (in minutes) that the Customer arrives
 */
Customer::Customer(double arrivalTime) {
	this->arrivalTime = arrivalTime;
	this->serviceStartTime = NULL_TIME;
	this->endTime = NULL_TIME;
	this->isServed = false;
}

/**
 * Renew every attributes of customer for second simulation
 */
void Customer::renew() {
	this->serviceStartTime = NULL_TIME;
	this->endTime = NULL_TIME;
	this->isServed = false;
}

/**
 * Retrieve the customer's arrival time
 * @return Customer's arrival time
 */
double Customer::getArrTime() {
	return this->arrivalTime;
}

/**
 * @return True if the Customer has been served, false otherwise
 */
bool Customer::isDone() {
	return isServed;
}

/**
 * Set service start time
 */
void Customer::setSerStartTime(double t) {
	this->serviceStartTime = t;
}

/**
 * Set service end time, after which the customer would leave the bank
 */
void Customer::setEndTime(double t) {
	this->isServed = true;
	this->endTime = t;
}

/**
 * @return Total amount of time this Customer spent in the Bank
 */
double Customer::getAllTime() {
	return endTime - arrivalTime;
}

/**
 * @return Service time for this Customer
 */
double Customer::getServiceTime() {
	return this->endTime - this->serviceStartTime;
}

/**
 * @return Waiting time for this Customer til his turn to be served
 */
double Customer::getWaitTime() {
	return this->serviceStartTime - this->arrivalTime;
}

Customer::~Customer() {
	// nothing needed, since no pointer in fields
}
