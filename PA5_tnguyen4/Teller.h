/**
 * Teller.h
 *
 * @author Dung (Kevin) Nguyen
 */

#ifndef TELLER_H_
#define TELLER_H_

#include "TellerQueue.h"
#include "EventQueue.h"
#include "CustomerEvent.h"
#define MAX_IDLE_TIME 600 // remember that this is in seconds

class TellerEvent;

class Teller {
public:
	Teller(int mainLine, double avgServiceTime);
	~Teller();
	bool isAvailable();
	bool justServed();
	bool justRested();
	void serveOrBreak(TellerQueue **lines, int size, EventQueue *eventQueue, double startTime);
	void updateServiceTime(double t);
	void updateIdleTime(double t);
	double getServiceTime();
	double getIdleTime();
	void renew(int mainLine);
private:
	int mainLine;
	double idleTime; // this will be in minutes
	double serviceTime; // also in minutes
	bool inService;
	bool onBreak;
	double start_time; // keep track of when start serve or rest
	double avgServiceTime;

	TellerQueue * checkOthers(TellerQueue **lines, int size);
	double randServiceT();
};

#endif
