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
	void act(TellerQueue **lines, int size, EventQueue *events);

private:
	TellerQueue * getCustomerLine(TellerQueue **lines, int size);
	Customer *customer;
};

#endif
