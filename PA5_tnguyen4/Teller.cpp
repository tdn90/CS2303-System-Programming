#include "TellerEvent.h"
#include "Teller.h"

Teller::Teller(int mainLine, double avgServiceTime) {
	this->mainLine = mainLine;
	this->idleTime = 0;
	this->serviceTime = 0;
	this->inService = false;
	this->onBreak = false;
	this->start_time = 0;
	this->avgServiceTime = avgServiceTime;
}

void Teller::renew(int mainLine) {
	this->mainLine = mainLine;
	this->idleTime = 0;
	this->serviceTime = 0;
	this->inService = false;
	this->onBreak = false;
	this->start_time = 0;
}

double Teller::getServiceTime() {
	return this->serviceTime;
}

double Teller::getIdleTime() {
	return this->idleTime;
}

bool Teller::isAvailable() {
	return !onBreak && !inService;
}

bool Teller::justServed() {
	return inService;
}

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

//TODO
void Teller::serveOrBreak(TellerQueue **lines, int size, EventQueue *eventQueue, double startTime) {
	if (this->isAvailable()) {
		if (lines[mainLine]->size() > 0) { // if main service line has customer
			// Remove customer from the line
			Customer *currentC = lines[mainLine]->remove();

			// Generate random service time
			double rndSerTime = randServiceT();

			// create 2 events and add to eventQueue
			// create customer event first (completion of service)
			double endTime = startTime + rndSerTime;
			this->start_time = startTime;
			this->inService = true;
			currentC->setSerStartTime(startTime);
			currentC->setEndTime(endTime);
			Event * custE = new CustomerEvent(endTime, currentC);
			// create teller event
			Event *tellerE = new TellerEvent(endTime, this);

			// add both events to eventQueue
			eventQueue->add(custE);
			eventQueue->add(tellerE);
		}
		else {
			TellerQueue * availableLine = checkOthers(lines, size);
			if (availableLine) { // check other lines for waiting customer
				// Remove customer from the line
				Customer *currentC = availableLine->remove();

				// Generate random service time
				double rndSerTime = randServiceT();

				// create 2 events and add to eventQueue
				// create customer event first (completion of service)
				double endTime = startTime + rndSerTime;
				this->start_time = startTime;
				currentC->setSerStartTime(startTime);
				currentC->setEndTime(endTime);
				Event * custE = new CustomerEvent(endTime, currentC);

				// create teller event
				this->inService = true;
				Event *tellerE = new TellerEvent(endTime, this);

				// add both events to eventQueue
				eventQueue->add(custE);
				eventQueue->add(tellerE);
			}
			else { // no one? Go take a break
				// Generate random idle time, in minutes
				double rndIdleTime = (rand() % MAX_IDLE_TIME) / 60.0;

				double endTime = startTime + rndIdleTime;
				this->start_time = startTime;

				this->onBreak = true;
				// make teller event and add to event queue
				Event *tellerE = new TellerEvent(endTime, this);
				eventQueue->add(tellerE);
			}
		}
	}
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
