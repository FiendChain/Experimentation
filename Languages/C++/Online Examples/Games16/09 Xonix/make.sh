GCC="g++"
CFLAGS="-std=c++11"
LFLAGS="-lsfml-graphics -lsfml-window -lsfml-system"

$GCC -c main.cpp $CFLAGS
$GCC main.o -o sfml-app $CFLAGS $LFLAGS
