CFLAGS = -g -Wall

all:  sorttest sorttest2

sorttest2: sorttest2.o sort.o timesort.o
	gcc $(CFLAGS) sorttest2.o sort.o timesort.o -o sorttest2

sorttest: sorttest.o sort.o timesort.o
	gcc $(CFLAGS) sorttest.o sort.o timesort.o -o sorttest

sorttest.o: sorttest.c sort.h
	gcc $(CFLAGS) -c sorttest.c

sort.o: sort.c sort.h
	gcc $(CFLAGS) -c sort.c

timesort.o: timesort.c sort.h
	gcc $(CFLAGS) -c timesort.c

clean:
	rm -f  *.o sorttest
	rm -r -f html latex

docs:
	doxygen
