/**
 * doodlebug.cpp
 * @author: Dung (Kevin) Nguyen
 */
#include <iostream>
#include "doodlebug.h"

/**
 * Constructor for Doodlebug. Create an Doodlebug object
 * @param f_row row to place the Doodlebug in
 * @param f_row column to place the Doodlebug in
 */
Doodlebug::Doodlebug(int f_row, int f_col) : Organism(f_row, f_col){
	stepSinceLastEaten = 0;
}

/**
 * Destructor for Doodlebug
 */
Doodlebug::~Doodlebug(){
	// print out informative message to notify user
	//std::cout << "Bug starved to death..." << std::endl;
}

/**
 * @return the character representing the bug on the board
 */
char Doodlebug::draw() {
	return 'x';
}

/**
 * @return false because this is a bug
 */
bool Doodlebug::isPrey() {
	return false;
}

/**
 * @return true when the bug is starved to death.
 * Bug is starved to death if it has not eaten any ants
 * within the last 3 steps
 */
bool Doodlebug::starved() {
	return stepSinceLastEaten == 3;
}

/**
 * @param row row to place the Doodlebug in
 * @param col column to place the Doodlebug in
 * Set new coordinate for the Doodlebug, at the same time increase
 * its stepSurvived and stepSinceLastEaten.
 * This function should be invoked whenever the Doodlebug is moved,
 * so a new coord is set, and prevent the Doodlebug from being moved
 * again in the same turn
 */
void Doodlebug::setCoords(int row, int col) {
	this->row = row;
	this->col = col;
	stepSurvived++;
	move_able = false;
	stepSinceLastEaten++;
}

/**
 * This function should be invoked when the bug just ate an ant
 * Reset stepSinceLastEaten
 */
void Doodlebug::eat() {
	stepSinceLastEaten = 0;
}

/**
 * @return true if the Doodlebug is ready to breed.
 * Doodlebug is ready to breed when it has survived at least 8 steps
 */
bool Doodlebug::readyToBreed() {
	return stepSurvived >= 8;
}

/**
 * Make the new Doodlebug and reset the current Doodlebug stepSurvived
 * @return a pointer to the new Doodlebug
 */
Organism * Doodlebug::breed(int new_row, int new_col) {
	//std::cout << "New bug is born!\n";
	this->stepSurvived = 0; // reset stepSurvived until next breed
	return new Doodlebug(new_row, new_col);
}

