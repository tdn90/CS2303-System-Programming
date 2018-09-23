/*
 * ant.h
 *
 * Created on Sep 22, 2018
 * 	Author: Dung (Kevin) Nguyen
 */


#ifndef ANT_H_
#define ANT_H_

#include "organism.h"

class Ant : public Organism {
public:
	char draw();
	bool isPrey();
	bool readyToBreed();
	Organism * breed(int new_row, int new_col);

	Ant(int row, int col);
	~Ant();
};

#endif
