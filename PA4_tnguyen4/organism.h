/*
 * organism.h
 *
 * This is an abstract class
 * Virtual functions will be implemented in Ant and Doodlebug
 *
 * Created on Sep 22, 2018
 * 	Author: Dung (Kevin) Nguyeon
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	Organism(int row, int col);
	virtual ~Organism();
	void readyToMove();
	bool canMove();
	void initCoord(int row, int col);

	virtual void move(int row, int col) = 0;
	virtual char draw() = 0;
	virtual bool isPrey() = 0;
	virtual bool readyToBreed() = 0;
	virtual Organism * breed(int new_row, int new_col) = 0;

protected:
	bool move_able;
	int stepSurvived;
	int row;
	int col;
};

#endif
