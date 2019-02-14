#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#define DLL_DYNAMIC_LOAD
#include "DLL/IDLL.h"
#include "fmt/format.h"

typedef IDLL* (WINAPI* pGetDLLInstance)(void);

int main(int argc, char *argv[]) 
{ 
    std::vector<std::string> args(argv+1, argv+argc);
    if (args.size() <= 0) {
        std::cout << "Specify path of dll" << std::endl;
        return 0;
    }

    const std::string& dllFilePath = args.at(0);

    HINSTANCE dllHandle = LoadLibrary((LPCTSTR)dllFilePath.c_str()); 
    if (dllHandle != NULL) 
    { 
        pGetDLLInstance CreateDLLInstance = (pGetDLLInstance)GetProcAddress(dllHandle, "CreateDLLInstance");
        if (CreateDLLInstance == NULL) {
            std::cout << "Couldn't load dll creator from: " << dllFilePath << std::endl;
            return 0;
        }
        IDLL *dll = CreateDLLInstance();
        dll->helloWorld();
        {
            int a, b;
            std::cout << "Multiply(x, y): ";
            std::cin >> a >> b;
            int c = dll->multiply(a, b);
            std::cout << fmt::format("dll->multiply({0},{1})={2}", a, b, c) << std::endl;
        }
        FreeLibrary(dllHandle);       
    } else {
        std::cout << "Unable to load library: " << dllFilePath << std::endl;
    }
}