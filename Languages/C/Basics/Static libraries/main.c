#include <basicmath.h>
#include <stdio.h>

static void test_add_int(int, int);

int main(int argc, char *argv[])
{
    test_add_int(1, 10);
    return 0;
}

static void test_add_int(int a, int b)
{
    int result = add_int(a, b);
    printf("add_int(%d,%d)=%d\n", a, b, result);
}