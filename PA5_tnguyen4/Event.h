/**
 * Event.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "TellerQueue.h"

class EventQueue;

class Event {
public:
	Event(double t);
	double getTime();
	virtual ~Event() {};
	virtual void act(TellerQueue **lines, int size, EventQueue *events) = 0;
private:
	double time; // the starting time of this event
};

#endif
