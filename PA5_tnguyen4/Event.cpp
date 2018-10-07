/**
 * Event.cpp
 *
 * @author: Dung (Kevin) Nguyen
 */

#include "Event.h"
#include "EventQueue.h"

Event::Event(double t) {
	this->start_time = t;
}

double Event::getTime() {
	return this->start_time;
}


