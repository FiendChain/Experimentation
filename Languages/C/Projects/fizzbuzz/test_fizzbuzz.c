// #define NDEBUG 
#include "unittest.h"
#include "fizzbuzz.c"
#include "string.h"

int main(void) {
    START_TEST("fizzbuzz") {
        STRING_TEST("0 == 0", get_fizzbuzz_string(0), "fizzbuzz");
        STRING_TEST("3 == fizz", get_fizzbuzz_string(3), "fizz");
        STRING_TEST("5 == buzz", get_fizzbuzz_string(5), "buzz");
        STRING_TEST("15 == fizzbuzz", get_fizzbuzz_string(15), "fizzbuzz");
        STRING_TEST("-1 == -1", get_fizzbuzz_string(-1), "-1");
    }
    END_TEST

    return ALL_PASSED;
}