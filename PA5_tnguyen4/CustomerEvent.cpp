#include "CustomerEvent.h"

CustomerEvent::CustomerEvent(double t, Customer *customer) : Event(t) {
	this->customer = customer;
}

CustomerEvent::~CustomerEvent() {
	// do nothing here, we don't want to delete customer
}

//TODO
void CustomerEvent::act(TellerQueue **lines, int size, int curIndex, EventQueue *eventQueue) {

}

//TODO
void CustomerEvent::getInLine(TellerQueue **lines) {

}

//TODO
void CustomerEvent::leaveBank() {

}
