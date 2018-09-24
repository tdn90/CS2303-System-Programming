#include <iostream>

#include "ant.h"

Ant::Ant(int row, int col) : Organism(row, col) {
	//already initialized in Organism constructor
}

Ant::~Ant(){
	// deliberately empty
	std::cout << "Ant was eaten..." << std::endl;
}

char Ant::draw() {
	return 'o';
}

bool Ant::isPrey() {
	return true;
}

bool Ant::readyToBreed() {
	return stepSurvived >= 3;
}

Organism * Ant::breed(int new_row, int new_col) {
	std::cout << "New ant is born!\n";
	this->stepSurvived = 0; // reset stepSurvived until next breed
	return new Ant(new_row, new_col);
}
