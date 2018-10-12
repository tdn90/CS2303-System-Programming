# Event Driven Simulation

## Brief Description of this Program
An event-driven simulation is a computer program that mimics the behavior of people or objects in a system in response to events that occur at certain times.

Specifically, this program will simulate a simply, daily activity of people in a Bank. 

The major activities that we are tracking are: 

1. For customers:
    - Customer arrival. 
    - Customer leaving bank.
2. For Bank tellers: 
    - Teller's service for one customer. 
    - Teller's completion of service.
    - Teller's break. 

## Purpose 
1. Measure the average amount of time people spend between arriving at the bank and leaving the bank. 
2. Compare the efficiency between two possible bank setup: 
    - One customer line for each teller.
    - One common line for all tellers.

## Files and Dependencies
Below are the list of all files necessary for successfully build and run the program:
1. Customer.h
2. Customer.cpp
3. Teller.h
4. Teller.cpp
5. TellerQueue.h
6. TellerQueue.cpp
7. Event.h
8. Event.cpp
9. CustomerEvent.h
10. CustomerEvent.cpp
11. TellerEvent.h
12. TellerEvent.cpp
13. EventQueue.h
14. EventQueue.cpp
15. qSim.cpp: main program to run the simulation
16. Makefile: commands to compile the project properly. 

## How to build and run the program
1. Navigate to the source code folder. Check all the necessary files for compiling as above. 
2. Build the program: 

    `make all`

3. Run the program:

    `./qSim <#customers> <#tellers> <simulationTime> <averageServiceTime> [seed]`

    where: 
    - #customers: specified number of customers coming in the bank.
    - #tellers: specified number of tellers serving at the bank. 
    - SimulationTime: total time to be simulated, in minutes. For example, if simulationTime = 60, the simulation will run from t = 0 (minute) to t = 60 (minute). Still, just as the real world's bank, if there are customers coming in near the closing time, the bank will still serve all of them. 
    - AverageServiceTime: the average service time of each teller. 
    - seed (optional argument): seed given to setup the random generator.

4. Results for both simulated setups will be printed to the screen. Enjoy!

## Program Design
1. Event (superclass): abstract class, with virtual function act()
2. CustomerEvent (subclass of Event):
3. TellerEvent (subclass of Event):
4. TellerQueue: represents a waiting line (FIFO queue)
5. EventQueue: major component of program, used to keep track of vital events and act accordingly. 
6. Customer: represent a customer using bank service 
7. Teller: serving the customer

## Data Analysis
Let's denote our 2 bank setups - one line per teller and one common line for all - as A and B accordingly. 
1. Generally, the average amount of time a customer spent in the bank for A is more than that for B. 
2. The maximum wait time for customers for A is also greater than that of B.
3. As the number of customers and bank teller increases, both situation does not show much difference (probably due to even distribution)

## My thoughts on this program 
1. This is a great program that simulates some real-world activity. 
2. Specifications provided are just enough to make a good design for this program in a short period of time.
3. The power of polymorphism is used.
4. Once the design is figured out, coding and debugging was relatively easy. 

## Ideas for improvement
1. Make the array of TellerQueue (basically all lines in the bank) a separate class, with functions such as getEmptyLine(), getShortestLine(), etc. 

## Author
This program is designed and implemented by Dung (Kevin) Nguyen, the owner of this repository, with guidance and advice from Professor Ciaraldi at Worcester Polytechnic Institute.


