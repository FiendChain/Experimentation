#include "unittest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug_print.h"

int _unittests_ran = 0;
int _unittests_passed = 0;
int _unittests_failed = 0;
int _all_passed = 1;

// format the unittest messages
#ifdef __MINGW32__
const char *fail_message = "%s test %02d: %s\n";
const char *pass_message = "%s test %02d: %s\n";
#elif __linux__
const char *fail_message = "\e[0;31m%s test %02d: %s\e[0m\n";
const char *pass_message = "\e[0;32m%s test %02d: %s\e[0m\n";
#else
const char *fail_message = "%s test %02d: %s\n";
const char *pass_message = "%s test %02d: %s\n";
#endif

// print header for a unittest batch
void _start_unittest(const char *name) {
    char buffer[MAX_UNITTEST_BUFFER] = {0};  
    snprintf(buffer, MAX_UNITTEST_BUFFER, " Running unittests: %s ", name);
    _print_unittest_header(buffer, '=');
}

// show sub category
void _show_unittest_category(const char *category) {
    printf("> %s\n", category);
}

// run a bool unittest
int _run_bool_unittest(const char *message, const char* expression_string, int expression, const char *file, int line) {
    const char *display_message = (message) ? message : expression_string;
    if (!expression) {
        _show_test_unittest(display_message, expression_string, file, line);
    } else {
        _show_test_unittest(display_message, NULL, file, line);
    }
    
    return expression;
}

// run a string unittest
int _run_string_unittest(const char *message, const char *expected, const char *given, const char *file, int line) {
    char display_message[MAX_UNITTEST_BUFFER] = {0};
    if (message) {
        snprintf(display_message, MAX_UNITTEST_BUFFER, "%s", message);
    } else {
        snprintf(display_message, MAX_UNITTEST_BUFFER, "%s == %s", expected, given);
    }
    
    int status = strcmp(expected, given);
    if (status != 0) {
        char error_message[MAX_UNITTEST_BUFFER] = {0};
        snprintf(error_message, MAX_UNITTEST_BUFFER, "Expected: '%s', Given: '%s'", expected, given);
        _show_test_unittest(display_message, error_message, file, line);
    } else {
        _show_test_unittest(display_message, NULL, file, line);
    }
}

// float unittest
int _run_float_unittest(const char *message, float expected, float given, const char *file, int line) {
    char display_message[MAX_UNITTEST_BUFFER] = {0};
    if (message) {
        snprintf(display_message, MAX_UNITTEST_BUFFER, "%s", message);
    } else {
        snprintf(display_message, MAX_UNITTEST_BUFFER, "%f == %f", expected, given);
    }

    float difference = expected-given;
    difference = (difference > 0) ? difference : -difference;
    int status = difference <= expected*MAX_FLOAT_DIFF_PERCENT;
    if (!status) {
        char error_message[MAX_UNITTEST_BUFFER] = {0};
        snprintf(error_message, MAX_UNITTEST_BUFFER, "Expected: '%f', Given: '%f'", expected, given);
        _show_test_unittest(display_message, error_message, file, line);
    } else {
        _show_test_unittest(display_message, NULL, file, line);
    }
}

// print status of test
void _show_test_unittest(const char *message, const char *error_message, const char *file, int line) {
    _unittests_ran++;
    if(error_message != NULL) {
        DEBUG_PRINT(fail_message, "Failed", _unittests_ran, message);
        DEBUG_PRINT("%s\n", error_message);
        DEBUG_PRINT("File '%s' at line '%d'.\n", file, line);
        _unittests_failed++;
    } else {
        DEBUG_PRINT(pass_message, "Passed", _unittests_ran, message);
        _unittests_passed++;
    }
    _all_passed &= (error_message == NULL);
}

// show unittest results
void _show_unittest_results() {
    char buffer[MAX_UNITTEST_BUFFER] = {0};
    snprintf(buffer, MAX_UNITTEST_BUFFER, "| Passed %d out of %d tests |", _unittests_passed, _unittests_ran);
    _print_unittest_header(buffer, '-');
    _reset_unittest();
    DEBUG_PRINT("\n");
}

// check if all passed
int _check_all_passed() {
    DEBUG_PRINT("%s\n", _all_passed ? "All tests passed" : "Some tests have failed");
    return _all_passed;
}

// resetall
void _reset_unittest() {
    _unittests_ran = _unittests_passed = _unittests_failed = 0;
}

// print header
void _print_unittest_header(const char *header, char sep) {
    int length = strlen(header);
    _print_unittest_separator(length, sep);
    DEBUG_PRINT("%s\n", header);
    _print_unittest_separator(length, sep);
}

// print separator
void _print_unittest_separator(int length, char c) {
    for(int i = 0; i < length; i++) {
        DEBUG_PRINT("%c", c);
    }
    DEBUG_PRINT("\n");
}
