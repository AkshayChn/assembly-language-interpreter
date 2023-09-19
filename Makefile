CFLAGS = -Wall -Werror -std=c++11

all: instruction.cpp instruction.hpp
	g++  $(CFLAGS) ali.hpp ali.cpp instruction.hpp instruction.cpp hardware.hpp hardware.cpp -o output

clean:
	rm output