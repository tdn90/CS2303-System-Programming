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
	justMoved = false;
}

Organism::~Organism() {
	// deliberately empty
}

void Organism::setCoords(int row, int col) {
	this->row = row;
	this->col = col;
	stepSurvived++;
}







