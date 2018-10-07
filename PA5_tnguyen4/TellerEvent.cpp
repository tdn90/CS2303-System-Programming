#include "TellerEvent.h"

TellerEvent::TellerEvent(double t, Teller *teller) : Event(t) {
	this->teller = teller;
}

//TODO
void TellerEvent::act(TellerQueue **lines, int size, int curIndex, EventQueue *eventQueue) {

}

//TODO
void TellerEvent::decide(TellerQueue **lines, int curIndex, EventQueue *eventQueue) {

}

TellerEvent::~TellerEvent() {

}
