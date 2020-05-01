CXX=g++
CXXFLAGS = -Wall -ggdb -O0 -std=c++11

all: Solution_Manual Solution_SmartPtr

Solution_Manual: Solution_Manual.o
	$(CXX) $(CXXFLAGS) -o Solution_Manual Solution_Manual.cpp

Solution_SmartPtr: Solution_SmartPtr.o
	$(CXX) $(CXXFLAGS) -o Solution_SmartPtr Solution_SmartPtr.cpp

clean:
	rm -f *.o Solution_Manual Solution_SmartPtr *~