#include "CustomerEvent.h"

CustomerEvent::CustomerEvent(double t, Customer *customer) : Event(t) {
	this->customer = customer;
}

CustomerEvent::~CustomerEvent() {
	// do nothing here, we don't want to delete customer
}

//TODO
void CustomerEvent::act(TellerQueue **lines, int size, EventQueue *eventQueue) {
	if (this->customer->isDone()) { // Customer already get served
		// collect statistic
		this->customer->setEndTime(this->getTime());
	}
	else { // customer just arrived
		// Customer get in line

		// get line for customer
		TellerQueue * shortestLine = getCustomerLine(lines, size);

		// put customer into the line
		shortestLine->add(customer);
	}
}

/**
 * Helper function for act
 * Attempt to retrieve the shortest line given the array of lines
 * Pre-condition: size >= 1
 * @param lines array of lines
 * @size represents the number of lines
 * @return Pointer to the shortest line
 */
TellerQueue * CustomerEvent::getCustomerLine(TellerQueue **lines, int size) {
	int min = lines[0]->size(); // set first line's length to minimum size
	TellerQueue * shortestLine = lines[0];
	for (int i = 1; i < size; i++) {
		if (lines[i]->size() < min) {
			min = lines[i]->size();
			shortestLine = lines[i];
		}
 	}
	return shortestLine;
}
