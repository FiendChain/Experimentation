#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);
    
    if (argc >= 2)
        printf("Echoing \'%s\'\n", argv[1]);

    return 0;
}