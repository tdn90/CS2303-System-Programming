#Assignment 3 Section A: String Libary Functions Implementation

##Funtions Implemented
+ size_t mystrlen1(const char* s);
+ size_t mystrlen2(const char* s);
+ char* mystrdup1(const char* src);
+ char* mystrdup2(const char* src);
+ char *mystrcpy(char *dest, const char *src);
+ char *mystrcat(char *dest, const char *src);
+ char *mystrncat(char *dest, const char *src, size_t n);
+ char *mystrncpy(char *dest, const char *src, size_t n);
+ char *mystrndup(const char *s, size_t n);

##Brief information about the program
+ `mystring.c` includes all implementations of the above functions.
+ `mystring.h` includes all prototypes of the above functions.
+ `ctest.c` is the source code to test the above functions by comparing
their result against the standard functions provided for strings.
+ makefile to compile and generate the executable file.

##Running the program
###From the command line (BASH)
1. Compile the code and generate the executable `ctest` by running
		`make all`
2. Run the executable ctest:
		`./ctest`

###From Eclipse:
1. Right click on the project, and choose `Build Project`
2. Set up the run configuration for the program. 
3. Run the program by clicking the Run button. 

###Extra: generate Documentation with Doxygen
+ Run `make docs` to build documentation html file and LaTex documentation. 

##Author
This assignment is implemented by Dung (Kevin) Nguyen, with guidance from
Prof. Ciaraldi of Worcester Polytechnic Institute, as well as the specifications
from the Linux man page 3. 
