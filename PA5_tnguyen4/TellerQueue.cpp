/**
 * TellerQueue.cpp
 *
 * @author Dung (Kevin) Nguyen
 */

#include "TellerQueue.h"

/**
 * Constructor
 */
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
	TQNode *newNode = new TQNode(c); // create a pointer to a new TQNode
	// Queue is empty
	if (!head) {
		head = tail = newNode;
	}
	// Queue has one element, add to the end
	else {
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

/**
 * Remove the Customer at the head of this queue
 * Warning: user should have checked whether this queue is empty before
 * calling this function.
 * @return Pointer to the customer removed, or NULL if Queue is empty
 */
Customer * TellerQueue::remove() {
	// remove from empty queue
	if (!head) return NULL;
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

/**
 * Destructor
 */
TellerQueue::~TellerQueue() {
	// deliberately empty, since we don't want to delete the Customers
}


