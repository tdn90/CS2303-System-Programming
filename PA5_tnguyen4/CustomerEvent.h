/**
 * CustomerEvent.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

#include "Event.h"
#include "Customer.h"

class CustomerEvent:public Event {
public:
	CustomerEvent(double t, Customer *customer);
	~CustomerEvent();

	void act(TellerQueue **lines, int size, int curIndex, EventQueue *eventQueue);
private:
	void getInLine(TellerQueue **lines);
	void leaveBank();
	Customer *customer;
};

#endif
