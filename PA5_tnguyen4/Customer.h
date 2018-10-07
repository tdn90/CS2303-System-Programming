/**
 * Customer.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>

class Customer {
public:
	Customer(double arrivalTime);
	~Customer();
	bool isDone();
private:
	double arrivalTime;
	double serviceStartTime;
	double endTime;
	bool isServed;
};

#endif
