/**
 * Event.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>
#include "TellerQueue.h"

class EventQueue;

class Event {
public:
	Event(double t);
	double getTime();
	virtual ~Event() {};
	virtual void act(TellerQueue **lines, int size, int curIndex, EventQueue *eventQueue) = 0;
private:
	double start_time; // the starting time of this event
};

#endif
