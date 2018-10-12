/**
 * TellerEvent.cpp
 *
 * @author Dung (Kevin) Nguyen
 */

#include "TellerEvent.h"
#include "Teller.h"

/**
 * @param mainLine The main service line of this Teller
 * @param avgServiceTime Specified average service time passed in CLI arguments
 */
Teller::Teller(int mainLine, double avgServiceTime) {
	this->mainLine = mainLine;
	this->idleTime = 0;
	this->serviceTime = 0;
	this->inService = false;
	this->onBreak = false;
	this->start_time = 0;
	this->avgServiceTime = avgServiceTime;
}

/**
 * Reset all necessary attributes to do second simulation
 */
void Teller::renew(int mainLine) {
	this->mainLine = mainLine;
	this->idleTime = 0;
	this->serviceTime = 0;
	this->inService = false;
	this->onBreak = false;
	this->start_time = 0;
}

/**
 * @return Total service time in minutes for this Teller over the simulation
 */
double Teller::getServiceTime() {
	return this->serviceTime;
}

/**
 * @return Total idle time in minutes for this Teller over the simulation
 */
double Teller::getIdleTime() {
	return this->idleTime;
}

/**
 * @return True if this Teller is available to serve, False otherwise
 */
bool Teller::isAvailable() {
	return !onBreak && !inService;
}

/**
 * @return True if this Teller is on service. False otherwise
 */
bool Teller::justServed() {
	return inService;
}

/**
 * @return True if this Teller is taking a break. False otherwise
 */
bool Teller::justRested() {
	return onBreak;
}

/**
 * @param t is the end time of this service
 */
void Teller::updateServiceTime(double t) {
	this->serviceTime += t - this->start_time;
	this->start_time = 0;
	this->inService = false;
}

/**
 * @param t is the end time of this break
 */
void Teller::updateIdleTime(double t) {
	this->idleTime += t - this->idleTime;
	this->start_time = 0;
	this->onBreak = false;
}

/**
 * Pre-condition: size >= 1
 * @param lines Array of lines in the bank
 * @param size Number of lines in the bank
 * @event Pointer to event queue
 * Make this Teller Event act depending on the situation
 * Teller when comes back from break or finish serving will look for another
 * customer, either in their line or other lines. If no one is found,
 * then go on break
 */
void Teller::serveOrBreak(TellerQueue **lines, int size, EventQueue *eventQueue,
		double startTime) {
	if (this->isAvailable()) {
		if (lines[mainLine]->size() > 0) { // if main service line has customer
			// Remove customer from the line
			Customer *currentC = lines[mainLine]->remove();
			addFutureEvents(startTime, currentC, eventQueue);
		} else {
			TellerQueue * availableLine = checkOthers(lines, size);
			if (availableLine) { // check other lines for waiting customer
				// Remove customer from the line
				Customer *currentC = availableLine->remove();
				addFutureEvents(startTime, currentC, eventQueue);
			} else { // no one? Go take a break
					 // Generate random idle time, in minutes
				double rndIdleTime = (rand() % MAX_IDLE_TIME) / 60.0;

				double endTime = startTime + rndIdleTime;
				this->start_time = startTime;
				this->onBreak = true;
				// make teller event for completing break and add to event queue
				Event *tellerE = new TellerEvent(endTime, this);
				eventQueue->add(tellerE);
			}
		}
	}
}

/**
 * Helper for serveOrBreak
 */
void Teller::addFutureEvents(int startTime, Customer *c, EventQueue *eventQueue) {
	// Generate random service time
	double rndSerTime = randServiceT();

	// create 2 events and add to eventQueue

	// create customer event first (completion of service)
	double endTime = startTime + rndSerTime;
	c->setSerStartTime(startTime);  // start service for customer
	c->setEndTime(endTime);
	Event * custE = new CustomerEvent(endTime, c);

	// set start time for this teller
	this->start_time = startTime;
	// create future teller event
	this->inService = true;
	Event *tellerE = new TellerEvent(endTime, this);

	// add both events to eventQueue
	eventQueue->add(custE);
	eventQueue->add(tellerE);
}

/**
 * Helper method to generate random service Time
 * @return a random service time in minutes
 */
double Teller::randServiceT() {
	return 2 * avgServiceTime * rand() / double(RAND_MAX);
}

/**
 * Helper function for serveOrBreak
 * @param lines Array of lines in the Bank
 * @param size Represent the number of lines in the Bank
 * @return Pointer to the line other than the main line that has a customer waiting.
 * Return NULL if all other lines are empty
 */
TellerQueue * Teller::checkOthers(TellerQueue **lines, int size) {
	for (int i = 0; i < size; i++) {
		if (i != mainLine && lines[i]->size() > 0) {
			return lines[i];
		}
	}
	return NULL;
}

Teller::~Teller() {
	// nothing to do
}
