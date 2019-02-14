CC=g++
CFLAGS=-std=c++17
LFLAGS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

pong: pong.o Ball.o Paddle.o PaddleBot.o Vector.o Config.o
	$(CC) *.o -o pong $(CFLAGS) $(LFLAGS)
pong.o:	  pong.cpp 	 
Ball.o:	  Ball.cpp  
	$(CC) -c Ball.cpp $(CFLAGS)
Paddle.o: Paddle.cpp 
PaddleBot.o: PaddleBot.cpp
Vector.o: Vector.cpp 
Config.o: Config.cpp

clean:
	rm -f *.o pong core