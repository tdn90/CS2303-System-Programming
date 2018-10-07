#include "TellerQueue.h"
#include <iostream>

TellerQueue::TellerQueue() {
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

/**
 * Add a customer to the end of the line
 * @param c Customer to be added
 */
void TellerQueue::add (Customer *c) {
	length++;
	// Queue is empty
	TQNode *newNode = new TQNode(c);
	if (!head && head == tail) {
		head = tail = newNode;
	}
	// Queue has one element, add to the end
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

/**
 * Remove the Customer at the head of this queue
 * @return Pointer to the customer removed, or NULL if Queue is empty
 */
Customer * TellerQueue::remove() {
	// remove from empty queue
	if (!head && head == tail) return NULL;
	else {
		Customer *result = head->customer;
		if (length == 1) { // only one element, set both to null
			head = tail = NULL;
		}
		else { // else move head forward
			head = head->next;
		}
		length--;
		return result;
	}
}

/**
 * @return the size of this queue
 */
int TellerQueue::size() {
	return this->length;
}

TellerQueue::~TellerQueue() {
	delete head;
	delete tail;
}


