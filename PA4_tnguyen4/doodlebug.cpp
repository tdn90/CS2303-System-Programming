#include <iostream>

#include "doodlebug.h"

Doodlebug::Doodlebug(int f_row, int f_col) : Organism(f_row, f_col){
	stepSinceLastEaten = 0;
}

Doodlebug::~Doodlebug(){
	std::cout << "Bug starved to death..." << std::endl;
}

char Doodlebug::draw() {
	return 'x';
}

bool Doodlebug::isPrey() {
	return false;
}

bool Doodlebug::starved() {
	return stepSinceLastEaten == 3;
}

void Doodlebug::setCoords(int row, int col) {
	this->row = row;
	this->col = col;
	stepSurvived++;
	move_able = false;
	stepSinceLastEaten++;
}

void Doodlebug::eat() {
	stepSinceLastEaten = 0;
}

bool Doodlebug::readyToBreed() {
	return stepSurvived >= 8;
}

Organism * Doodlebug::breed(int new_row, int new_col) {
	std::cout << "New bug is born!\n";
	this->stepSurvived = 0; // reset stepSurvived until next breed
	return new Doodlebug(new_row, new_col);
}

