CC=g++
CFLAGS=-std=c++11
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

main: main.o application.o creature.o random.o
	$(CC) *.o -o game $(CFLAGS) $(LFLAGS)
main.o:   main.cpp
	$(CC) -c main.cpp $(CFLAGS)
application.o: Source/Application.cpp 	 
	$(CC) -c Source/Application.cpp $(CFLAGS)
creature.o: Source/Creature.cpp  
	$(CC) -c Source/Creature.cpp $(CFLAGS)
random.o: Source/Random.cpp
	$(CC) -c Source/Random.cpp $(CFLAGS)

clean:
	rm -f *.o game core
