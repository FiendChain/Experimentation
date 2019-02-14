#include "App/App.hpp"
#include <stdio.h>

int main(int argc, char *argv[]) {
    App app(1920, 1080, 120, 10);
    app.run();
    
    return EXIT_SUCCESS;
}