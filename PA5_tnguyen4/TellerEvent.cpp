/**
 *
 * TellerEvent.cpp
 * @author Dung (Kevin) Nguyen
 */

#include "TellerEvent.h"

/**
 * @param t Time (in minutes) that this event happens
 */
TellerEvent::TellerEvent(double t, Teller *teller) : Event(t) {
	this->teller = teller;
}

/**
 * Pre-condition: size >= 1
 * @param lines Array of lines in the bank
 * @param size Number of lines in the bank
 * @event Pointer to event queue
 * Make this Teller Event act depending on the situation
 */
void TellerEvent::act(TellerQueue **lines, int size, EventQueue *eventQueue) {
	if (this->teller->justServed()) {
		// update service time
		this->teller->updateServiceTime(this->getTime());
	}
	else if (this->teller->justRested()) {
		// update idle time
		this->teller->updateIdleTime(this->getTime());
	}
	this->teller->serveOrBreak(lines, size, eventQueue, this->getTime());
}

/**
 * Destructor
 */
TellerEvent::~TellerEvent() {
	// deliberately empty
}
