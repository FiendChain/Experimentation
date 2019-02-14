#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int fibonacci(int count);

int main(int argc, char *argv[]) {
    // stdout
    string helloWorld = "Hello world!";
    printf("c: %s\n", "Hello World!");                    
    cout << "c++: " << helloWorld << endl;  
    // stdin
    int count = 20;
    cout << "fib(" << count << ")=" << fibonacci(count) << endl;

    return EXIT_SUCCESS;
}

int fibonacci(int count) {
    int x = 1, y = 1;
    for(int i = 0; i < count; i++) {
        int temp = x + y;
        x = y;
        y = temp;
    }
    return x;
}