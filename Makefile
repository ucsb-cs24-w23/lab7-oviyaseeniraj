#MAKEFILE

CXXFLAGS: -std=c++11 -g -Wall -Wno -uninitialized

all: tests
		./tests

tests: heap.cpp examheap.cpp
	g++ $(CXXFLAGS) heap.cpp examheap.cpp -o tests

clean:
	rm tests