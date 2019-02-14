CC=gcc
CFLAGS=-std=c11
LFLAGS=-lX11 -lxdo

main: objects
	$(CC) *.o -o main $(CFLAGS) $(LFLAGS)

objects: 
	$(CC) *.c -c  $(CFLAGS) $(LFLAGS)

clean:
	rm -f *.o main core