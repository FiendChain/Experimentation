CC := g++
CFLAGS := -O3 -std=c++17

all: prog_a prog_b

prog_a: prog_a.o
	$(CC) $< -o $@ $(CFLAGS)

prog_a.o: prog_a.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

prog_b: prog_b.o
	$(CC) $< -o $@ $(CFLAGS)
	
prog_b.o: prog_b.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
	
clean:	
	rm -rf *.o prog_a prog_b
