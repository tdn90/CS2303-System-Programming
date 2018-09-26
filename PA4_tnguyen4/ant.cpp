/**
 * ant.cpp
 * Author: Dung (Kevin) Nguyen
 */

#include <iostream>
#include "ant.h"

/**
 * Constructor for Ant. Create an Ant object
 * @param row row to place the ant in
 * @param col column to place the ant in
 */
Ant::Ant(int row, int col) : Organism(row, col) {
	//already initialized in Organism constructor
}

/**
 * Destructor for ant
 */
Ant::~Ant(){
	// print out informative message to notify user
	//std::cout << "Ant was eaten..." << std::endl;
}

/**
 * @return the character representing the ant on the board
 */
char Ant::draw() {
	return 'o';
}

/**
 * @return true because this is an ant
 */
bool Ant::isPrey() {
	return true;
}

/**
 * @param row row to place the ant in
 * @param col column to place the ant in
 * Set new coordinate for the ant, at the same time increase
 * its stepSurvived.
 * This function should be invoked whenever the ant is moved,
 * so a new coord is set, and prevent the ant from being moved
 * again in the same turn
 */
void Ant::setCoords(int row, int col) {
	this->row = row;
	this->col = col;
	stepSurvived++;
	move_able = false;
}

/**
 * @return true if the ant is ready to breed.
 * Ant is ready to breed when it has survived at least 3 steps
 */
bool Ant::readyToBreed() {
	return stepSurvived >= 3;
}

/**
 * Make the new ant and reset the current ant's stepSurvived
 * @return a pointer to the new ant
 */
Organism * Ant::breed(int new_row, int new_col) {
	//std::cout << "New ant is born!\n";
	this->stepSurvived = 0; // reset stepSurvived until next breed
	return new Ant(new_row, new_col);
}
