#Executable Name
EXENAME = exec
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = Airport.o main.o airport_graph.o Flight.o BFS.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

test: output_msg catch/catchmain.cpp tests/tests.cpp airport_graph.cpp Airport.cpp BFS.cpp Flight.cpp
	$(LD) catch/catchmain.cpp tests/tests.cpp airport_graph.cpp Airport.cpp BFS.cpp Flight.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test


