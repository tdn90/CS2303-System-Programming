#include "EventQueue.h"
#include "Event.h"

EventQueue::EventQueue() {
	this->head = NULL;
	this->length = 0;
}

int EventQueue::size() {
	return length;
}

/**
 * Add the event according to its occurring time
 * @param e Event to be added
 *
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
		while (!cursor->next && cursor->next->e->getTime() < newNode->e->getTime()) {
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
 * Trigger the action of the event
 * @return the Event being removed, NULL if queue is empty
 */
Event * EventQueue::remove() {
	if (!head) return NULL; // queue is empty
	else {
		Event *result = head->e;
		if (length == 1) {
			head = NULL;
		}
		else {
			head = head->next;
		}
		length--;
		return result;
	}
}
