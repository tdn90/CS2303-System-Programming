# PA4 
# Author: Dung (Kevin) Nguyen
# Sep 22, 2018

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS = PA4.o

LIBS =

TARGET = PA4

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
	
PA4.o: PA4.cpp
	$(CXX) -c $(CXXFLAGS) PA4.cpp
	
board.o: board.cpp board.h
	$(CXX) -c $(CXXFLAGS) board.cpp

ant.o: ant.cpp ant.h
	$(CXX) -c $(CXXFLAGS) ant.cpp
	
doodlebug.o: doodlebug.cpp doodlebug.h
	$(CXX) -c $(CXXFLAGS) doodlebug.cpp

organism.o: organism.cpp organism.h
	$(CXX) -c $(CXXFLAGS) organism.cpp
	
all :	$(TARGET)

clean: 
	rm -rf *.o $(TARGET)

