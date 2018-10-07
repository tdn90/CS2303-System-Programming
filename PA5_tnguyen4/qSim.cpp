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
	if (argc == 5) srand(seed);
	else srand(time(NULL));

	Customer *listOfCust[customers];
	// Make the customers
	for (int i = 0; i < customers; i++) {
		double arrTime = simulationTime * rand() / double(RAND_MAX);
	}

	Teller *listOfTel[tellers];

	return 1;
}

