CC=g++
CFLAGS=-std=c++17
LFLAGS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
DFLAGS=-DDEBUG=0

main: objects 
	$(CC) *.o -o main $(CFLAGS) $(LFLAGS) 
objects:
	$(CC) -c *.cpp $(CFLAGS) $(LFLAGS) $(DFLAGS)

clean:
	rm -f main *.o core

check: main
	valgrind --leak-check=full ./main
