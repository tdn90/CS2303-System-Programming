/**
 * TellerEvent.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"
#include "Teller.h"

class TellerEvent:public Event {
public:
	TellerEvent(double t, Teller *teller);
	~TellerEvent();

	void act(TellerQueue **lines, int size, EventQueue *eventQueue);
private:
	Teller *teller;
};

#endif
