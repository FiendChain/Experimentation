/* file: unittest.h */
#ifndef _UNIT_TEST_H_
#define _UNIT_TEST_H_

#ifdef NDEBUG
#define BOOL_TEST(MESSAGE, EXPRESSION) ((void)0)
#define STRING_TEST(MESSAGE, EXPECTED, GIVEN) ((void)0)
#define FLOAT_TEST(MESSAGE, EXPECTED, GIVEN) ((void) 0)
#define START_TEST(NAME) ((void) 0)
#define SHOW_CATEGORY(NAME) ((void) 0)
#define END_TEST ((void)0);
#define ALL_PASSED 0
#else
#define BOOL_TEST(MESSAGE, EXPRESSION) _run_bool_unittest(MESSAGE, #EXPRESSION, EXPRESSION, __FILE__, __LINE__)
#define STRING_TEST(MESSAGE, EXPECTED, GIVEN) _run_string_unittest(MESSAGE, EXPECTED, GIVEN, __FILE__, __LINE__)
#define FLOAT_TEST(MESSAGE, EXPECTED, GIVEN) _run_float_unittest(MESSAGE, EXPECTED, GIVEN, __FILE__, __LINE__)
#define START_TEST(NAME) _start_unittest(NAME);
#define SHOW_CATEGORY(NAME) _show_unittest_category(NAME);
#define END_TEST _show_unittest_results();
#define ALL_PASSED _check_all_passed()
#endif

#define MAX_UNITTEST_BUFFER 500
#ifndef MAX_FLOAT_DIFF_PERCENT
#define MAX_FLOAT_DIFF_PERCENT 0.001
#endif

void _start_unittest(const char *);
void _show_unittest_category(const char *);
// unittest types
int _run_bool_unittest(const char *message, const char *expression_string, int expression, const char *file, int line);
int _run_string_unittest(const char *message, const char *expected, const char *given, const char *file, int line);
int _run_float_unittest(const char *message, float expected, float given, const char *file, int line);
// print unittest status
void _show_test_unittest(const char *message, const char *error_message, const char *file, int line);
void _show_unittest_results();
int _check_all_passed();
void _reset_unittest();
void _print_unittest_header(const char *, char);
void _print_unittest_separator(int, char);

#endif