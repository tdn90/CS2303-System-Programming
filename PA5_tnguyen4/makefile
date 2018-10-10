# PA5
# Author: Dung (Kevin) Nguyen
# Sep 28, 2018

CXXFLAGS = -g -Wall -fmessage-length=0

OBJS = qSim.o Customer.o Teller.o CustomerEvent.o TellerEvent.o Event.o TellerQueue.o EventQueue.o

TARGET = qSim

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	
qSim.o: Customer.h Teller.h CustomerEvent.h TellerEvent.h Event.h TellerQueue.h EventQueue.h
	$(CXX) -c $(CXXFLAGS) qSim.cpp

TellerEvent.o: Event.h Teller.h
	$(CXX) -c $(CXXFLAGS) TellerEvent.cpp
	
Teller.o: Teller.h 
	$(CXX) -c $(CXXFLAGS) Teller.cpp
	
CustomerEvent.o: Customer.h Event.h
	$(CXX) -c $(CXXFLAGS) CustomerEvent.cpp
	
EventQueue.o: Event.h
	$(CXX) -c $(CXXFLAGS) EventQueue.cpp
	
Event.o: Event.h TellerQueue.h 
	$(CXX) -c $(CXXFLAGS) Event.cpp
	
TellerQueue.o: Customer.h
	$(CXX) -c $(CXXFLAGS) TellerQueue.cpp
	
Customer.o: Customer.h
	$(CXX) -c $(CXXFLAGS) Customer.cpp
	
all:	$(TARGET)

clean: 
	rm -rf *.o $(TARGET)
	rm -rf html latex
	
docs: 
	doxygen