#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>

#include "../main/arraylist.h"
#include "test.h"

static void print_list(ArrayList *list, char* format)
{
    printf("    ");
    arraylist_print(list, format);
    printf("\n");
}

void arraylist_test()
{
    test_describe("ArrayList");
    
    ArrayList *list = arraylist_create();

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    arraylist_push(list, &a);
    arraylist_push(list, &b);
    arraylist_push(list, &c);
    arraylist_push(list, &d);
    print_list(list, "%d");

    test_expr("should have a size of 4", list->size == 4);
    test_expr("should retrieve the third element", *(int*) arraylist_get(list, 2) == 3);

    int e = 5;
    arraylist_insert(list, &e, 2);
    print_list(list, "%d");

    test_expr("should have inserted element on third index", *(int*) arraylist_get(list, 2) == 5);

    arraylist_remove(list, 2);
    print_list(list, "%d");

    test_expr("should have removed the third element", *(int*) arraylist_get(list, 2) == 3);

    int *p = arraylist_pop(list);
    print_list(list, "%d");

    test_expr("should remove the last element", *p == 4);
    test_expr("should have a size of 3", list->size == 3);

    arraylist_destroy(list);
}
