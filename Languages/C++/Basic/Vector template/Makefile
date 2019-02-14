CC=g++
CFLAGS=-std=c++17
LFLAGS=
DFLAGS=

main: objects
	$(CC) *.o -o main $(CFLAGS) $(LFLAGS) $(DFLAGS)

objects:
	$(CC) *.cpp -c $(CFLAGS) $(LFLAGS) $(DFLAGS)

clean:
	rm -f *.o main core
	