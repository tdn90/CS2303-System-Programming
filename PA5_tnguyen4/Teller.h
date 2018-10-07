/**
 * Teller.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef TELLER_H_
#define TELLER_H_

#include <iostream>
#define MAX_IDLE_TIME 600

class Teller {
public:
	Teller(double idleTime);
	~Teller();
	bool isAvailable();
	bool justServed();
	bool justIdled();
private:
	double idleTime;
	double serviceTime;
	bool inService;
	bool onBreak;
};

#endif
