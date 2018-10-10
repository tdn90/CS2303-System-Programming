/*
 * qSim.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: tnguyen4
 */
#include <iostream>
#include "Customer.h"
#include "Teller.h"
#include "CustomerEvent.h"
#include "TellerEvent.h"
#include "Event.h"
#include "TellerQueue.h"
#include "EventQueue.h"
using std::cout;
using std::endl;

void getCustomerStatistics(Customer **arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Customer " << i << ": " << arr[i]->getAllTime() << "\n";
	}
}

void getTellerStatistics(Teller **arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Idle time for teller " << i << ": " << arr[i]->getIdleTime() << "\n";
		cout << "Service time for teller " << i << ": " << arr[i]->getServiceTime() << "\n";
	}
}

void renewTellers(Teller **arr, int size, int mainLine) {
	for (int i = 0; i < size; i++) {
		arr[i]->renew(mainLine);
	}
}

void renewCustomers(Customer **arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i]->renew();
	}
}



bool isTerminateState(Customer **arr, int size) {
	for (int i = 0; i < size; i++) {
		if (!arr[i]->isDone()) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int customers; // keep track of the number of customers
	int tellers; // keep track of number of tellers
	double simulationTime; // simulation time in unit of minutes
	double averageServiceTime;  // average service time in unit of minutes
	long seed; // seed for random generator

	// check user input
	if (argc != 5 && argc != 6) {
		cout << "Usage:" << endl;
		cout << "./qSim #Customers #tellers simulationTime averageServiceTime [seed]";
		return EXIT_FAILURE;
	}

	//TODO: maybe add more checks to user's input if required
	if (argc >= 5) {
		customers = atoi(argv[1]);
		tellers = atoi(argv[2]);
		simulationTime = atof(argv[3]);
		averageServiceTime = atof(argv[4]);
	}
	if (argc == 6) seed = atol(argv[5]);

	// set up random generator
	if (argc == 6) srand(seed);
	else srand(time(NULL));

	cout << "Customers: " <<  customers <<  "\n";
	cout <<  "Tellers: " <<  tellers <<  "\n";
	cout <<  "Simulation Time: " <<  simulationTime <<  "\n";
	cout <<  "averageServiceTime: " <<  averageServiceTime << "\n";

	// --------------------- SITUATION 1: MULTIPLE LINES-------------------------
	EventQueue *events = new EventQueue();
	Customer * arrOfCust[customers];
	for (int i = 0; i < customers; i++) {
		double randArrTime = simulationTime * rand() / double(RAND_MAX);
		Customer *newCust = new Customer(randArrTime);
		arrOfCust[i] = newCust;
		Event *custE = new CustomerEvent(randArrTime, newCust);
		events->add(custE);
	}

	Teller *arrOfTellers[tellers];



	for (int i = 0; i < tellers; i++) {
		Teller *tel = new Teller(i, averageServiceTime);
		arrOfTellers[i] = tel;
		Event *telE = new TellerEvent(0, tel);
		events->add(telE);
	}

	TellerQueue *lines[tellers];
	for (int i = 0; i < tellers; i++) {
		lines[i] = new TellerQueue();
	}

	while (events->size() > 0) {
		Event *currentE = events->remove();
		currentE->act(lines, tellers, events);
		if (isTerminateState(arrOfCust, customers)) break;
	}

	getCustomerStatistics(arrOfCust, customers);
	getTellerStatistics(arrOfTellers, tellers);


	// ------------------ SITUATION 2: ONE FOR ALL -----------------
	EventQueue *events2 = new EventQueue();
	renewTellers(arrOfTellers, tellers, 0);
	renewCustomers(arrOfCust, customers);
	for (int i = 0; i < customers; i++) {
		Customer *curC = arrOfCust[i];
		Event *custE = new CustomerEvent(curC->getArrTime(), curC);
		events2->add(custE);
	}

	for (int i = 0; i < tellers; i++) {
		Event *telE = new TellerEvent(0, arrOfTellers[i]);
		events2->add(telE);
	}

	TellerQueue *lines2[1];
	lines2[0] = new TellerQueue();
	while (events->size() > 0) {
		Event *currentE = events->remove();
		currentE->act(lines2, 1, events);
		if (isTerminateState(arrOfCust, customers))
			break;
	}

	getCustomerStatistics(arrOfCust, customers);
	getTellerStatistics(arrOfTellers, tellers);

	return 1;
}

