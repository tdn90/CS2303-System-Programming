/**
 * EventQueue.cpp
 *
 * @author Dung (Kevin) Nguyen
 */

#include "Event.h"
#include "EventQueue.h"

/**
 * Constructor
 */
EventQueue::EventQueue() {
	this->head = NULL;
	this->length = 0;
}

/**
 * @return the size of this event queue
 */
int EventQueue::size() {
	return length;
}

/**
 * Add the event according to its occurring time
 * @param e Event to be added
 */
void EventQueue::add(Event *e) {
	EQNode *newNode = new EQNode(e);
	// add to empty queue
	if (!head) {
		head = newNode;
	}
	// add before head
	else if (e->getTime() < head->e->getTime()) {
		newNode->next = head;
		head = newNode;
	}
	// add after head
	else {
		EQNode *cursor = head;
		/* stop before the event that is later
		 * than the added event
		 */
		while (cursor->next && cursor->next->e->getTime() <= newNode->e->getTime()) {
			cursor = cursor->next;
		}
		/*
		 * After while loop, cursor stops at either:
		 * The end of the queue OR
		 * The node prev is where
		 * prev < insertedNode < next
		 */
		if (!cursor->next) { // add at the end of queue
			cursor->next = newNode;
		}
		else {
			newNode->next = cursor->next;
			cursor->next = newNode;
		}
	}
	length++;
}

/**
 * Remove the event at the head of this queue (earliest event)
 * @return the Event being removed, NULL if queue is empty
 */
Event * EventQueue::remove() {
	if (!head) return NULL; // queue is empty
	else {
		Event *result = head->e;
		if (length == 1) { // only one element, simply set head to null
			head = NULL;
		}
		else { // more than one, then move head forward
			head = head->next;
		}
		length--;
		return result;
	}
}

/**
 * Destructor
 */
EventQueue::~EventQueue() {

}
