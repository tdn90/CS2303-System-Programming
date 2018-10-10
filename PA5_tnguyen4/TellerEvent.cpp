#include "TellerEvent.h"

TellerEvent::TellerEvent(double t, Teller *teller) : Event(t) {
	this->teller = teller;
}

//TODO
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

TellerEvent::~TellerEvent() {

}
