#include <iostream>
#include <vector>
#include <string>

void printLine(const std::string& line);

int main(int argc, char *argv[])
{
    std::string buffer;
    std::vector<std::string> lines(0);
    while (std::getline(std::cin, buffer))
    {
        printLine(buffer);    
        lines.push_back(buffer);
    }

    return 0;
}

void printLine(const std::string& line)
{
    static int count = 0;
    std::cout << '[' << ++count << "]:" << line << std::endl; 
}
