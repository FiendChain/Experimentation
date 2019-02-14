#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    int total_loops = 0;
    int delay = 1000;
    try {
       total_loops = argc >= 2 ? std::stoi(argv[1]) : total_loops;
       delay = argc >= 3 ? std::stoi(argv[2]) : delay;
    } catch (const std::invalid_argument& e) {
        if (argc >= 2)
            std::cout << argv[1] << " invalid loop count" << std::endl;
        if (argc >= 3)
            std::cout << argv[2] << " invalid delay" << std::endl;
    }

    for (int i = 0; i < total_loops; i++)
    {
        std::cout << i << std::endl;
        Sleep(delay);
    }
}
