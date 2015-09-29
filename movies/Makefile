#
# Makefile for CS 70 Asciimation Assignment

our-movie: our-movie.o movie.o sprite.o
	clang++ -o our-movie our-movie.o movie.o sprite.o -lncurses

movie.o: movie.cpp movie.hpp
	clang++ -c -g -std=c++11 -pedantic -Wall -Wextra movie.cpp

sprite.o: sprite.cpp sprite.hpp
	clang++ -c -g -std=c++11 -pedantic -Wall -Wextra sprite.cpp

our-movie.o: our-movie.cpp 
	clang++ -c -g -std=c++11 -pedantic -Wall -Wextra our-movie.cpp

clean:
	rm -f our-movie movie.o sprite.o our-movie.o
