OBJS = main.o alphabet.o nfa.o state.o
BINARY = nfa.out
CFLAGS = -g

all: program

program: $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o $(BINARY)

main.o: main.cpp nfa.hpp
	g++ $(CFLAGS) -c main.cpp

nfa.o: alphabet.hpp state.hpp nfa.cpp
	g++ $(CFLAGS) -c nfa.cpp

state.o: state.cpp
	g++ $(CFLAGS) -c state.cpp

alphabet.o: alphabet.cpp
	g++ $(CFLAGS) -c alphabet.cpp

clean:
	rm $(OBJS)

cleanall:
	rm $(OBJS) $(BINARY)