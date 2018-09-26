/*
 * doodlebug.h
 *
 * Created on Sep 22, 2018
 * 	Author: Dung (Kevin) Nguyen
 */


#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "organism.h"

class Doodlebug : public Organism {
public:
	char draw();
	bool isPrey();
	bool readyToBreed();
	Organism * breed(int new_row, int new_col);
	bool starved();
	void eat();
	void move(int row, int col);

	Doodlebug(int row, int col);
	~Doodlebug();

private:
	int stepSinceLastEaten;
};

#endif
