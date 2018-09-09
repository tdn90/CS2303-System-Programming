# Set CFLAGS to activate all warnings and enable debugger
CFLAGS = -Wall -g

# Default rule is to build the executable called life
all: life

# Rule for building the executable.
life: life.o twoD.o term.o gridConfig.o readFile.o
	gcc $(CFLAGS) life.o twoD.o term.o gridConfig.o readFile.o -o life

# Rules for building each object file.
life.o: life.c twoD.h term.h gridConfig.h readFile.h
	gcc $(CFLAGS) -c life.c

twoD.o: twoD.c twoD.h gridConfig.h
	gcc $(CFLAGS) -c twoD.c

term.o: term.c term.h gridConfig.h
	gcc $(CFLAGS) -c term.c

gridConfig.o: gridConfig.c gridConfig.h
	gcc $(CFLAGS) -c gridConfig.c

readFile.o: readFile.c readFile.h
	gcc $(CFLAGS) -c readFile.c
	


# Give command "make clean" to remove object files,
#  executable, and documentation.
clean:
	rm -f *.o life
	rm -f -r html latex

# Give command "make docs" to create documentation.	
docs:
	doxygen
