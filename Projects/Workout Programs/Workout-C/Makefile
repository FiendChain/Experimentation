CC=gcc
CFLAGS=-lbsd

workout: workout.o readInfo.o timing.o
	$(CC) workout.o readInfo.o timing.o -o workout $(CFLAGS)
workout.o: workout.c readInfo.h
readInfo.o: readInfo.c readInfo.h
timing.o: timing.c timing.h
clean:
	rm -f workout *.o core
