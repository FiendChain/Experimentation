#include "Source/Application.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
/**
    PREDATOR AND PREY CELLULAR AUTOMATON

    The world is grid of cells, with 3 possibilities: Predator(Red), Prey(Green), or Empty(Black).

    Both predator and prey have a set health, that changes over time.

    The simulation works in steps, with the following rules:

        -For prey:
            -Tries to move in a random direction.
            -Health increases.
            -When health reaches a threshold:
                -They will reproduce, creating a new "Prey"
                -Their health resets to 1

        -For predator:
            -Tries to move in a random direction.
            -Health decreases.
            -When health reaches 0, they die and turn into "Nothing".
            -If the adjacent square is a prey:
                -They will eat it, turning it into a "predator" (reproducing)
                -Their health will increase by the amount of health the eaten prey had
*/

int main(int argc, char *argv[])
{
    int w = 1300, h = 700;
    for(int i = 1; i < argc; i++) {
        if(sscanf(argv[i], "w=%d", &w) == 1);
        else if(sscanf(argv[i], "h=%d", &h) == 1);
    }

    Application app(w, h);;
    app.run();
    return 0;
}
