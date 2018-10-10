/**
 * Customer.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#define NULL_TIME -1

class Customer {
public:
	Customer(double arrivalTime);
	~Customer();
	bool isDone();
	void setSerStartTime(double t);
	void setEndTime(double t);
	double getAllTime();
	void renew();
	double getArrTime();
private:
	double arrivalTime;
	double serviceStartTime;
	double endTime;
	bool isServed;
};

#endif
