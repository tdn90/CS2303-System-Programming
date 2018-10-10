/*
 * qSim.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: tnguyen4
 */
#include <iostream>
#include <cmath>
#include "Customer.h"
#include "Teller.h"
#include "CustomerEvent.h"
#include "TellerEvent.h"
#include "Event.h"
#include "TellerQueue.h"
#include "EventQueue.h"

using std::cout;
using std::endl;
using std::sqrt;

double averageTimeInBank(Customer **arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i]->getAllTime();
	}
	return sum / size;
}

double stdev(Customer **arr, int size, int mean) {
	double sqSum = 0;
	for (int i = 0; i < size; i++) {
		sqSum += (arr[i]->getAllTime() - mean) * (arr[i]->getAllTime() - mean);
	}
	return sqrt(sqSum / size);
}

double getMaxWaitTime(Customer **arr, int size) {
	double maxWaitTime = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i]->getWaitTime() > maxWaitTime) {
			maxWaitTime = arr[i]->getWaitTime();
		}
	}
	return maxWaitTime;
}

//TODO
void getFinalStatistics(Customer **arr1, int size1, Teller **arr2, int size2, int option) {
	cout << "Total number of customers served: " << size1 << endl;

	cout << "Number of tellers: " << size2 << endl;
	if (option) { // option is 1 means one line per teller
		cout << "Type of Queuing: One line per Teller" << endl;
	}
	else { // one common line for all tellers
		cout << "Type of Queuing: One common line for all tellers" << endl;
	}

	double avg = averageTimeInBank(arr1, size1);
	cout << "Average amount of time a customer spent in the bank: " << avg << endl;
	cout << "Standard deviation: " << stdev(arr1, size1, avg) << endl;

	cout << "Maximum wait time for customers: " << getMaxWaitTime(arr1, size1) << endl;

	double totalServiceTime = 0;
	double totalIdleTime = 0;
	for (int i = 0; i < size2; i++) {
		totalServiceTime += arr2[i]->getServiceTime();
		totalIdleTime += arr2[i]->getIdleTime();
	}
	cout << "Total amount of teller service time: " << totalServiceTime << endl;
	cout << "Total amount of teller idle time: " << totalIdleTime << endl;
}


void getCustomerStatistics(Customer **arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Customer " << i << ": " << arr[i]->getAllTime() << endl;
	}
}

void getTellerStatistics(Teller **arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Idle time for teller " << i << ": " << arr[i]->getIdleTime() << endl;
		cout << "Service time for teller " << i << ": " << arr[i]->getServiceTime() << endl;
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
		cout << "./qSim #Customers #tellers simulationTime averageServiceTime [seed]" << endl;
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

	cout << "Customers: " <<  customers <<  endl;
	cout <<  "Tellers: " <<  tellers <<  endl;
	cout <<  "Simulation Time: " <<  simulationTime <<  endl;
	cout <<  "averageServiceTime: " <<  averageServiceTime << endl;

	// --------------------- SITUATION 1: MULTIPLE LINES-------------------------
	cout << "\n--------------SIMULATION 1--------------" << endl;
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

	//getCustomerStatistics(arrOfCust, customers);
	//getTellerStatistics(arrOfTellers, tellers);
	getFinalStatistics(arrOfCust, customers, arrOfTellers, tellers, 1);


	// ------------------ SITUATION 2: ONE FOR ALL -----------------
	cout << "\n--------------SIMULATION 2--------------" << endl;
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
	while (events2->size() > 0) {
		Event *currentE = events2->remove();
		currentE->act(lines2, 1, events2);
		if (isTerminateState(arrOfCust, customers))
			break;
	}

	//getCustomerStatistics(arrOfCust, customers);
	//getTellerStatistics(arrOfTellers, tellers);
	getFinalStatistics(arrOfCust, customers, arrOfTellers, tellers, 0);

	return 1;
}

