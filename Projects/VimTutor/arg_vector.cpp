#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv+1, argv+argc);
    std::cout << "Total parameters: " << args.size() << std::endl;
    for (const auto& arg: args)
    {
        std::cout << arg << std::endl;
    }

    std::string buffer;
    std::vector<std::string> pipedInputs(0);
    while (std::getline(std::cin, buffer))
    {
        pipedInputs.push_back(buffer);
    }
    std::cout << "Total piped lines: " << pipedInputs.size() << std::endl;
    for (const auto& line: pipedInputs)
        std::cout << line << std::endl;

    return 0;
}

