#ifndef TEST_H
#define TEST_H

#include <stdbool.h>

/**
 * Print a summary of all tests.
 * @returns True if all tests passed, otherwise false.
 */
bool test_summary();

/**
 * Describe a test suite.
 * @param description Test suite description
 */
void test_describe(char* description);

/**
 * Assert true.
 * @param description Test description
 * @param expr The expression
 */
void test_expr(char* description, bool expr);

/**
 * Assert string equality.
 * @param description Test description
 * @param s1 First string
 * @param s2 Second string
 */
void test_str_eq(char* description, char* s1, char* s2);

/**
 * Print a region of memory.
 * @param ptr Pointer to start address
 * @param nbytes Number of bytes to read
 */
void print_memory(void *ptr, unsigned int nbytes);

#endif