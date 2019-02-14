#include "vector.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Vector2f v1;
    Vector2f v2(5, 2);

    std::cout << "v1=" << v1;
    std::cout << "v2=" << v2;
    std::cin >> v1;
    std::cout << "v1=" << v1;

    return 0;
}