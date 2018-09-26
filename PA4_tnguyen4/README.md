# Programming Assignment 4: Polymorphism

Implement a simple 2D predator-prey simulation using derived classes and virtual functions in C++.

## Essential files to run the program
1. Header files:
- Organism.h
- Ant.h
- Board.h 
2. Source code files:
- PA4.cpp: main program
- Board.cpp: handling the board and the game's logic
- Organism.cpp: Abstract class representing an organism, whose virtual functions are implemented in Ant.cpp and Doodlebug.cpp
- Ant.cpp: include all functions needed for the Ant object
- Doodlebug.cpp: include all functions needed for the Doodlebug object.
3. Makefile: used to compile the source code and generate the executables. 

## How to compile and run the program
1. Navigate to the source code directory. Check all the essential files given above.
2. Compile the source code to generate binary executable:

    `make all`
3. Run the program:
   
    `./PA4 [gridSize] [doodlebugs] [ants] [time_steps] [seed] [pause]`

    where:
    + gridSize: an integer representing the number of cells along one dimension of the grid (defaulting to 20 if not specified).
    + doodlebugs: an integer indicating the number of doodlebugs (default 5)
    + ants: an integer indicating the number of ants (default 100)
    + time_steps: the number of time steps to play (default 1000)
    + seed: an integer indicating the seed for the random number generator, with zero meaning to use the current time as the seed (default seed value is 1)
    + pause: an indication as to whether to pause. Blank or zero means do not pause. A non-negative value n means pause and print the grid after each nth step. Wait for one character input before continuing.

4. Enjoy!
5. Generate doxygen (html or latex pages for documentation):

    `doxygen`


## Brief Description of the Game
1. Simulate a 2D grid of n-by-n squares, some of which may be occupied by one Organism. 
2. Two type of Organism: 
- Doodlebug (predator)
- Ant (prey) 
3. Ant's behavior / movement:
- For every time step, an ant will try to find an empty cell surrounding it and move there.
- If no empty cell is found, that ant stays in the same cell.
- If an ant survives for at least 3 steps, at the end of the third step, the ant gives birth to a new ant in an adjacent empty cell. 
- If no empty cell is found, then no birth can be given. In this case, the ant can wait for the next time step and attempt to breed again.
4. Doodlebug's behavior / movement:
- The bug's main goal is to find an ant to eat. So it will first look for any adjacent cell that contains an ant. If found, then the bug will move to the ant's cell and eat the ant.
- If no ant is found, the bug will attempt to find an empty cell around it, and move there.
- If no ants / empty cell is found, then the bug get stuck in its current cell.  
- Starvation: if the bug has not eaten any ants for the last three time steps, at the end of the third time step, it starves to death and is removed from the grid.
- If the bug has survived for at least 8 time steps, then it gives birth to a new bug in an empty cell surrounding it. If no empty cell is available, then it waits for the next turn to give birth.
5. Any cell that is out of bound of the grid is considered invalid.
6. During each time step, the bugs will act before the ants.
7. An organism's neighbors are the upper, right, lower, left cell of its current position. No diagonals move are allowed.

## Reflections on this program
1. It is more likely that all the bugs will be dead at the end of the game, due to the fact that it get starved so easily (only after 3 rounds without eating an ant).
2. The ants generally have high survival rate, since it does not die of starvation, and its breeding condition is fairly easy to achieve (after 3 surviving steps).
3. Several thoughts on improving this program:
- Instead of using a 1D array of size 2 to represent the coordinate, it might be a better design to define a struct called Coord which has two fields: x and y.
- Instead of using a 2D array, it might be better to use Vectors and Iterator to represent and go through the grid.
- Instead of declaring pointers to objects explicit using the `new` keyword, it would be better to use "[smart pointers](https://stackoverflow.com/questions/106508/what-is-a-smart-pointer-and-when-should-i-use-one)". 

## Author
This program is designed and implemented by Dung (Kevin) Nguyen, the owner of this repository. The instructions and requirements are provided by Professor Ciaraldi of Worcester Polytechnic Institute.
