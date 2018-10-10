/**
 * Event.cpp
 *
 * @author: Dung (Kevin) Nguyen
 */

#include "Event.h"

Event::Event(double t) {
	this->time = t;
}

double Event::getTime() {
	return this->time;
}


