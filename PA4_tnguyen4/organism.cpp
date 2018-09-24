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
	move_able = true;
}

Organism::~Organism() {
	// deliberately empty
}

void Organism::setCoords(int row, int col) {
	this->row = row;
	this->col = col;
	stepSurvived++;
	move_able = false;
}

bool Organism::canMove() {
	return move_able;
}

void Organism::readyToMove() {
	move_able = true;
}





