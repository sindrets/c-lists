#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../main/clonelist.h"
#include "test.h"

typedef struct {
    char a;
    char b;
    long c;
    long d;
} MockStruct;

static void print_list(CloneList *list, char* format)
{
    printf("    ");
    clonelist_print(list, format);
}

void clonelist_test()
{
    test_describe("CloneList");
    
    CloneList *list = clonelist_create(sizeof(int));
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    clonelist_push(list, &a);
    clonelist_push(list, &b);
    clonelist_push(list, &c);
    clonelist_push(list, &d);
    print_list(list, "%d");

    test_expr("should have a size of 4", list->size == 4);
    test_expr("should retrieve the third element", *(int*)clonelist_get(list, 2) == 3);

    int e = 5;
    clonelist_insert(list, &e, 2);
    print_list(list, "%d");

    test_expr("should have inserted element on third index", *(int*) clonelist_get(list, 2) == 5);

    free(clonelist_remove(list, 2));
    print_list(list, "%d");

    test_expr("should have removed the third element", *(int*) clonelist_get(list, 2) == 3);

    int *p = clonelist_pop(list);
    print_list(list, "%d");

    test_expr("should remove the last element", *p == 4);
    test_expr("should have a size of 3", list->size == 3);
    free(p);

    clonelist_destroy(list);

    list = clonelist_create(sizeof(MockStruct));

    MockStruct sA = { 1, 2, 3, 4 };
    MockStruct sB = { 5, 6, 7, 8 };
    MockStruct sC = { 9, 10, 11, 12 };
    clonelist_push(list, &sA);
    clonelist_push(list, &sB);
    clonelist_push(list, &sC);

    MockStruct *sBClone = (MockStruct*) clonelist_get(list, 1);
    test_expr("should store and retieve the whole struct", (
        sB.a == sBClone->a &&
        sB.b == sBClone->b &&
        sB.c == sBClone->c &&
        sB.d == sBClone->d
    ));

    clonelist_destroy(list);
}