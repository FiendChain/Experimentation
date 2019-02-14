#include <iostream>
#include "CMakeTutorialConfig.h"
#include "Vector.hpp"
#include "App.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Major: " << CMake_Tutorial_VERSION_MAJOR << " " <<
                 "Minor: " << CMake_Tutorial_VERSION_MINOR << std::endl;
    std::cout << "CMake hello" << std::endl;
    App app(640, 480, 30);
    std::cout << app.GetResolution();

    return 0;
}