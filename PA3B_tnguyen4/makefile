all: structest

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall

structest: structest.o mystruct.o
	gcc $(CFLAGS) structest.o mystruct.o -o structest

structest.o: structest.c mystruct.h
	gcc $(CFLAGS) -c structest.c

mystruct.o: mystruct.c mystruct.h
	gcc $(CFLAGS) -c mystruct.c

clean:
	rm -f *.o structest
	rm -f -r html latex

docs:
	doxygen
	# Following lines are only needed if we want to access doc pages
	#   using a Web server.
	#chmod go+r html/*
	#cp html/* ~/public_html/cs2303assig3
