GCC=g++
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

$(GCC) -c main.cpp
$(GCC) main.o -o sfml-app $(LFLAGS)
