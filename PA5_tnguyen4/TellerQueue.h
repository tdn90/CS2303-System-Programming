/**
 * TellerQueue.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

#include "Customer.h"

class TellerQueue {
public:
	TellerQueue();
	~TellerQueue();

	void add(Customer *c);
	Customer * remove();
	int size();
private:
	class TQNode {
	public:
		TQNode(Customer *c) {
			this->customer = c;
			this->next = NULL;
		};
		~TQNode() {
			/* do nothing here, we don't want to delete the
			 * customer or the next node
			 */
		};
		Customer *customer;
		TQNode *next;
	};

	int length;
	TQNode *head;
	TQNode *tail;
};

#endif
