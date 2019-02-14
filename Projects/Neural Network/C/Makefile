CC=gcc
CFLAGS=-std=c11 
LFLAGS=-lm
DFLAGS=

main: objects
	$(CC) *.o -o main $(CFLAGS) $(LFLAGS) $(DFLAGS)
objects:
	$(CC) -c *.c $(CFLAGS) $(LFLAGS) $(DFLAGS)

clean:
	rm -f *.o main core