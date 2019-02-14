CC=g++
CFLAGS=-DSFML_STATIC
LLIB=-I .\SFML\include -L .\SFML\lib
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

sfml-test:
	$(CC) sfml-test.cpp -o sfml-test $(CFLAGS) $(LLIB) $(LFLAGS)

clean:
	rm -f *.o core sfml-test