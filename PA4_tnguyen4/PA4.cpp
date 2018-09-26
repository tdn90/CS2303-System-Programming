#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"

int main(int argc, char *argv[]) {
	int gridSize = 20; // width and height of the grid, default 20
	int doodlebugs = 5; // number of dooglebugs, default 5
	int ants = 100; //number of ants, default 100
	int time_steps = 1000; // number of steps to play, default 1000
	long seed = 1; // indicate the seed for random number generator, default 1
	int pause = 0; // indicate whether to pause, default 0 meaning pause disabled

	// check arguments
	if (argc > 1) {
		gridSize = atoi(argv[1]);
		if (argc > 2) {
			doodlebugs = atoi(argv[2]);
			if (argc > 3) {
				ants = atoi(argv[3]);
				if (argc > 4) {
					time_steps = atoi(argv[4]);
					if (argc > 5) {
						seed = atol(argv[5]);
						if (argc == 7) {
							pause = atoi(argv[6]); // get the first character
						}
						else if (argc > 7){ // too many arguments input
							std::cout << "You have provided too many arguments.\n" << std::endl;
							std::cout << "Usage:\n" << std::endl;
							std::cout << "./game gridSize #doodlebugs #ants #time_steps seed pause\n" << std::endl;
							return EXIT_FAILURE;
						}
					}
				}
			}
		}
	}

	// check appropriate gridSize
	if (gridSize <= 0) {
		std::cout << "Grid size must be positive.\n" << std::endl;
		return EXIT_FAILURE;
	}

	// check appropriate Doodlebugs
	if (doodlebugs < 0) {
		std::cout << "Doodlebugs cannot be negative.\n" << std::endl;
		return EXIT_FAILURE;
	}

	// check appropriate Ants
	if (ants < 0) {
		std::cout << "Ants cannot be negative.\n" << std::endl;
		return EXIT_FAILURE;
	}

	// check appropriate Time_steps
	if (time_steps < 0) {
		std::cout << "Time_steps cannot be negative.\n" << std::endl;
		return EXIT_FAILURE;
	}

	// check appropriate pause
	if (pause < 0) {
		std::cout << "Value of pause cannot be negative.\n" << std::endl;
		return EXIT_FAILURE;
	}

	// check that the grid can contain the total number of organism provided
	if (doodlebugs + ants > gridSize * gridSize) {
		std::cout << "Too many organisms specified for the grid!" << gridSize
				<< std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Grid Size: " << gridSize << std::endl;
	std::cout << "Doodlebugs: " << doodlebugs << std::endl;
	std::cout << "Ants: " << ants << std::endl;
	std::cout << "Time_steps: " << time_steps << std::endl;
	std::cout << "seed: " << seed << std::endl;
	std::cout << "pause: " << pause << std::endl;

	std::cout << "-------------------START OF GAME-----------------------\n";
	srand(time(&seed)); // set different seed for random generator
	// Initialize the board
	Board *board = new Board(gridSize, ants, doodlebugs);
	std::cout << "Initial Board:" << std::endl;
	board->printBoard();
	std::cout << "Initial ants: " << board->getCurrentAnts() << "\n";
	std::cout << "Initial bugs: " << board->getCurrentBugs() << "\n";

	int turn = 0;
	while (turn < time_steps && board->setBoardReady()) {
		// pause enabled after [pause] step
		if (pause > 0) {
			if (turn != 1 && turn % pause == 0) {
				std::cout << "Press ENTER key to continue, or Ctrl - C to stop the program:" << std::endl;
				getchar();
			}
		}
		std::cout << "\n" << "Turn " << (turn+1) << "\n";
		board->updateBoard();
		board->printBoard();
		std::cout << "Remaining ants: " << board->getCurrentAnts() << "\n";
		std::cout << "Remaining bugs: " << board->getCurrentBugs() << "\n";
		turn++;
	}
	std::cout << "Total number of ants in game: " << board->getAllAnts() << "\n";
	std::cout << "Total number of bugs in game: " << board->getAllBugs() << "\n";
	std::cout << "Remaining ants: " << board->getCurrentAnts() << "\n";
	std::cout << "Remaining bugs: " << board->getCurrentBugs() << "\n";

	delete board; // done with program, free the memory on the heap
}

