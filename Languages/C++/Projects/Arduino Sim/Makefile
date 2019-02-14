CC=g++
CFLAGS=-DSFML_STATIC -std=c++17
LLIB=
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

main:
	$(CC) main.cpp Arduino.cpp -o main $(CFLAGS) $(LLIB) $(LFLAGS)

clean:
	rm -f main *.o core

check: main
	valgrind --leak-check=full ./main
