CC=g++
CFLAGS=-std=c++17
LFLAGS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

PIXELS=gameOfLifePixels
GRID =gameOfLifeGrid

main: objects 
	$(CC) $(PIXELS).o -o $(PIXELS) $(CFLAGS) $(LFLAGS)
	$(CC) $(GRID).o -o $(GRID) $(CFLAGS) $(LFLAGS)
objects:
	$(CC) -c $(PIXELS).cpp $(CFLAGS) $(LFLAGS)
	$(CC) -c $(GRID).cpp $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(PIXELS) $(GRID) *.o core

check: main
	valgrind --leak-check=full ./$(PIXELS)
	valgrind --leak-check=full ./$(GRID)
