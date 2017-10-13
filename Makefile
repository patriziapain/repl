all: repl

repl: repl.o 
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o repl repl.o 

repl.o: repl.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c repl.cpp

clean:
	rm -f repl.o