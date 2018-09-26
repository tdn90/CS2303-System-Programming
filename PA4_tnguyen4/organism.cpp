/**
 * Organism.cpp
 *
 * @author: Dung (Kevin) Nguyen
 */
#include <iostream>
#include "organism.h"

/**
 * Creates a new Organism (though this is an abstract)
 * @param row row to place the new Organism in
 * @param col column to place the new Organism in
 */
Organism::Organism(int row, int col) {
	initCoord(row, col);
	stepSurvived = 0;
	move_able = false;
}

/**
 * Destructor to delete the Organism
 */
Organism::~Organism() {
	// no pointers in this class, so this is deliberately empty
}

/**
 * @return true if this Organism can be moved, false otherwise
 */
bool Organism::canMove() {
	return move_able;
}

/*
 * Set the Organism to be ready for next move
 */
void Organism::readyToMove() {
	move_able = true;
}

/*
 * Set the initial coordinate for the Organism.
 */
void Organism::initCoord(int row, int col) {
	this->row = row;
	this->col = col;
}





