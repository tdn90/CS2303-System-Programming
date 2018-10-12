#include "CustomerEvent.h"

/**
 * @param t Time (in minute) that this Customer event happens
 * @param customer Pointer to the Customer arrived at the bank
 */
CustomerEvent::CustomerEvent(double t, Customer *customer) : Event(t) {
	this->customer = customer;
}

/**
 * Destructor
 */
CustomerEvent::~CustomerEvent() {
	// do nothing here, we don't want to delete customer
}

/**
 * Pre-condition: size >= 1
 * @param lines Array of lines in the bank
 * @param size Number of lines in the bank
 * @event Pointer to event queue
 * Make this Customer Event act depending on the situation
 */
void CustomerEvent::act(TellerQueue **lines, int size, EventQueue *eventQueue) {
	if (this->customer->isDone()) { // Customer already get served
		// collect statistic
		this->customer->setEndTime(this->getTime());
	}
	else { // customer just arrived, get in line
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

	/* i is current index in lines
	 * Loop through lines to choose the shortest line
	 */
	for (int i = 1; i < size; i++) {
		if (lines[i]->size() < min) {
			min = lines[i]->size();
			shortestLine = lines[i];
		}
 	}
	return shortestLine;
}
