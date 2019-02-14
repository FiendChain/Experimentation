CC=g++
CFLAGS=-std=c++17
LFLAGS=-lxdo -lsfml-graphics -lsfml-window -lsfml-system

main: objects
	$(CC) *.o -o main $(CFLAGS) $(LFLAGS)

objects:
	$(CC) *.cpp -c $(CFLAGS) $(LFLAGS)

clean:
	rm -f *.o main core