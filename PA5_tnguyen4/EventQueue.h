/**
 * EventQueue.h
 *
 * This event queue is sorted according to the
 * time of its event.
 *
 * The event with the earliest time is at the head of
 * this queue.
 *
 * @author: Dung (Kevin) Nguyen
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include <iostream>

class Event;

class EventQueue {
public:
	EventQueue();

	int size();
	void add(Event * e);
	Event * remove();

private:
	class EQNode {
	public:
		EQNode(Event * e) {
			this->e = e;
			this->next = NULL;
		};
		Event *e;
		EQNode *next;
	};
	int length;
	EQNode *head;
};

#endif
