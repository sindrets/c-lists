#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

const char *BLACK = "\x1b[30m";
const char *RED = "\x1b[31m";
const char *GREEN = "\x1b[32m";
const char *BG_RED = "\x1b[41m";
const char *BG_GREEN = "\x1b[42m";
const char *FG_RESET = "\x1b[39m";
const char *BG_RESET = "\x1b[49m";

int testCount = 0;
int passedCount = 0;

static void test_log(char* description, bool passed)
{
    passed ? 
        printf("  %s%s PASS %s%s", BG_GREEN, BLACK, FG_RESET, BG_RESET) : 
        printf("  %s%s FAIL %s%s", BG_RED, BLACK, FG_RESET, BG_RESET);
    printf(" %s\n", description);
    testCount++;
    if (passed) passedCount++;
}

bool test_summary()
{
    printf("\nPassed %d out of %d tests.\n\n", passedCount, testCount);
    bool passed = passedCount == testCount;
    passed ? 
        printf("%sTEST PASSED%s\n\n", GREEN, FG_RESET) : 
        printf("%sTEST FAILED%s\n\n", RED, FG_RESET);
    return passed;
}

void test_describe(char* description)
{
    printf("\nTest suite: %s\n\n", description);
}

void test_expr(char* description, bool expr)
{
    test_log(description, expr);
}

void test_str_eq(char* description, char* s1, char* s2)
{
    test_log(description, strcmp(s1, s2) == 0);
}

void print_memory(void *ptr, unsigned int nbytes)
{
    unsigned char *p = (unsigned char *)ptr;
    for (int i = 0; i < nbytes; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n\n");
}

#endif