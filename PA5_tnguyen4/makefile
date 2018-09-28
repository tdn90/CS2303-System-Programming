# PA5
# Author: Dung (Kevin) Nguyen
# Sep 28, 2018

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS = qSim.o

TARGET = qSim

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	
qSim.o: 
	$(CXX) -c $(CXXFLAGS) qSim.cpp
	
all:	$(TARGET)

clean: 
	rm -rf *.o $(TARGET)
	rm -rf html latex
	
docs: 
	doxygen