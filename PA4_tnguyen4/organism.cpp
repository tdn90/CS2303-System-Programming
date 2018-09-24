/**
 * Organism.cpp
 *
 * @author: Dung (Kevin) Nguyen
 */
#include <iostream>
#include "organism.h"

/**
 * Creates a new Organism (though this is an abstract)
 */
Organism::Organism(int row, int col) {
	this->row = row;
	this->col = col;
	stepSurvived = 0;
	move_able = false;
}

Organism::~Organism() {
	// deliberately empty
}

bool Organism::canMove() {
	return move_able;
}

void Organism::readyToMove() {
	move_able = true;
}

void Organism::initCoord(int row, int col) {
	this->row = row;
	this->col = col;
}





