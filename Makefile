# Makefile for MPI Pi Estimation Program

CXX=mpicxx
CXXFLAGS=-std=c++11

TARGET=pi_calc

SOURCES=main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: clean
