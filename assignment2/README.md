# GAME OF LIFE

This CLI (_Command Line Interface_) program will allow the user to simulate John Conway's **_Game of Life_** on the console / command line interface (_ex: BASH_), within the grid that is customized by the user. 

## Files needed to compile
1. Main program: life.c
2. File to make the executable program: makeFile
3. Dependencies:
+ _readFile.c_ and _readFile.h_: contain functions that analyze given initial configuration file.
+ _term.c_ and _term.h_: contain functions that help with the program's termination step.
+ _gridConfig.c_ and _gridConfig.h_: contain functions that help configuring the grid / generation.
+ _twoD.c_ and _twoD.h_: contain functions related to 2D arrays.

## How to run the program
1. Navigate to the folder containing the source code. 
2. Run the following code on command line:

`./life NR NC gens input [print] [pause]`

(* See below explanation for each argument)

3. Enjoy!


## Program arguments and input
The program should be invoked from the command line with the following arguments:

`./life NR NC gens input [print] [pause]`

where

+ **NR** and **NC** are unsigned integers indicating the number of elements in the y and x directions if the grid, re-spectively. In other words, the number of rows and columns, respectively, in the grid.
+ **gens** is the number of generations to play. This value must be greater than zero. The program will halt prior to this number of generations if it determines that the game has reached a ter-mination condition.
+ **input** is the name of a file containing a sequence of lines, each consisting of a sequence of 'x' and 'o' characters, indicating the occupied and unoccupied cells of the initial configuration. An ‘x’ indicates an occupied cell, an ‘o’ or a blank indicates an unoccupied cell. If a line is shorter than the width of the grid, cells to the right are considered unoccupied. If there are fewer lines in the file than the height of the grid, cells below are considered unoccupied. 
+ **print** is an _optional_ argument with value of 'y' or 'n' indicating whether each generation (including generation 0) should be printed or displayed before proceeding to the next generation. If this item is missing, it defaults to 'n'. 
+ **pause** is an _optional_ argument with value of 'y' or 'n' indicating whether a keystroke is needed between generations. If this and/or the print item is missing, it defaults to 'n'. It is not possible to specify a value for _pause_ if you do not also specify a value for _print_.

## General information about Game of Life
### Description
The Game of Life was invented by the mathematician John Conway and was originally described in the April 1970 issue of Scientific American (page 120). The Game of Life has since become an interesting object of mathematical study and amusement, and it is the subject of many websites.

The game is played on a rectangular grid of cells, so that each cell has eight neighbors (adjacent cells). Each cell is either occupied by an organism or not. A pattern of occupied and unoccupied cells in the grid is called a generation. 

### Rule
The rules for deriving a new generation from the previous generation are these:

1. **_Death_**: If an occupied cell has 0, 1, 4, 5, 6, 7, or 8 occupied neighbors, the organism dies (0 or 1 of loneliness; 4 thru 8 of overcrowding).
2. **_Survival_** : If an occupied cell has two or three neighbors, the organism survives to the next genera-tion.
3. **_Birth_**. If an unoccupied cell has precisely three occupied neighbors, it becomes occupied by a new organism.

### Termination condition
Once started with an initial configuration of organisms (Generation 0), the game continues from one generation to the next until one of three conditions is met for termination:
1. All organisms die
2. The pattern of organisms repeats itself from a previous generation 
3. A predefined number of generations is reached.

### Special rules / conditions for this specific program
1. It is responsible for terminating after a steady state is reached (current generation is the same as the previous) or an oscillation of two alternating patterns is reached.
2. In theory, the Game of Life is played on an infinite grid. This program, however, will play on a finite grid. The same rules apply, but squares beyond the edge of the grid are assumed to be always unoccupied.

## How the program works

1. Retrieve data from user input 

2. Allocate memory for grids based on the user's specification

3. Set up initial grid configuration based on the specified input file

4. Center the initial grid configuration

5. Play the game for as many generations as needed until one of the termination conditions is met

6. Print out final state and display termination condition

## Problems engaged when developing this program
1. Development would be more efficient with proper debugging technique and black box testing for c.
2. Figuring out the best design for the program. 
3. Had to learn quite several elements (such as memory allocation, read user's input / arguments, reading from a file).


## Author
This program is designed and implemented by Dung (Kevin) Nguyen, the owner of this repository, with guidance from Professor Ciaraldi at Worcester Polytechnic Institute. 







