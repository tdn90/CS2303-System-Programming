/**
 * Event.cpp
 *
 * @author: Dung (Kevin) Nguyen
 */

#include "Event.h"

/**
 * Constructor
 * @param t Time (in minutes) that this event happens
 */
Event::Event(double t) {
	this->time = t;
}

/**
 * @return Time that this event happens
 */
double Event::getTime() {
	return this->time;
}


