# PA4 
# Author: Dung (Kevin) Nguyen
# Sep 22, 2018

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS = board.o ant.o doodlebug.o organism.o PA4.o

TARGET = PA4

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	
PA4.o: PA4.cpp organism.h ant.h doodlebug.h board.h 
	$(CXX) -c $(CXXFLAGS) PA4.cpp
	
board.o: board.cpp board.h organism.h ant.h doodlebug.h
	$(CXX) -c $(CXXFLAGS) board.cpp

ant.o: ant.cpp ant.h organism.h
	$(CXX) -c $(CXXFLAGS) ant.cpp
	
doodlebug.o: doodlebug.cpp doodlebug.h organism.h
	$(CXX) -c $(CXXFLAGS) doodlebug.cpp

organism.o: organism.cpp organism.h
	$(CXX) -c $(CXXFLAGS) organism.cpp
	
	
all:	$(TARGET)

clean: 
	rm -rf *.o $(TARGET)
	rm -rf html latex
	
docs: 
	doxygen

