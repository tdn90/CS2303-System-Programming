# Assignment 3 Section B: Employee Structure
Implement and test functions related to a newly created Employee struct in C.

## How to compile and run
### From the command line (BASH)
1. Compile the code and generate the executable `structest` by running
  
     `make all`
2. Run the executable ctest:
		
     `./structest`

### From Eclipse:
1. Right click on the project, and choose
   
    `Build Project`

2. Set up the run configuration for the program. 
3. Run the program by clicking the Run button. 

### Extra: generate Documentation with Doxygen
+ Run `make docs` to build documentation html file and LaTex documentation. 

## General Info
1. Struct Employee consists of three following field:
+ `name`
+ `birth_year`
+ `start_year`

2. Included files:
+ `mystruct.c`: source code file containing implementations 
of all functions applied to struct Employee. 
+ `mystruct.h`: header file containing prototypes of all
functions applied to struct Employee.
+ `structest.c`: source code file to test functions related
to employees.
+ makefile: compile and generate executable file.

## Functions made for struct Employee
1. struct Employee *makeEmployee(int birth, int start, const char* name);


2. void printEmployee(struct Employee *e);

3. struct Employee* makeRandEmployee();
 
4. int randInt(int max);
5. char *randStr();
6. char randLowercase();
7. char randUppercase();

8. struct Employee **getRandListEmployee(int size);
9. void printEmployees(struct Employee **list, int count);

10. void freeArray(struct Employee **list, size_t count);

11. struct Employee **shallowCopy(struct Employee **list, int size);

12. struct Employee *deepCopyEmp(struct Employee *e);

13. struct Employee **deepCopyList(struct Employee **list, size_t size);


## Author: 
This assignment is implemented by Dung (Kevin) Nguyen, with guidance from
Prof. Ciaraldi of Worcester Polytechnic Institute.
