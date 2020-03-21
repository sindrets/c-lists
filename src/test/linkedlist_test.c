#include <stdio.h>

#include "../main/linkedlist.h"
#include "test.h"

static void print_list(LinkedList *list, char* format)
{
    printf("    ");
    linkedlist_print(list, format);
}

void linkedlist_test()
{
    test_describe("LinkedList");
    
    LinkedList *list = linkedlist_create();

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    linkedlist_push(list, &a);
    linkedlist_push(list, &b);
    linkedlist_push(list, &c);
    linkedlist_push(list, &d);
    print_list(list, "%d");

    test_expr("should have a size of 4", list->size == 4);
    test_expr("should retrieve the third element", *(int*) linkedlist_get(list, 2) == 3);

    int e = 5;
    linkedlist_insert(list, &e, 2);
    print_list(list, "%d");

    test_expr("should have inserted element on third index", *(int*) linkedlist_get(list, 2) == 5);

    linkedlist_remove_pos(list, 2);
    print_list(list, "%d");

    test_expr("should have removed the third element", *(int*) linkedlist_get(list, 2) == 3);

    int *p = linkedlist_pop(list);
    print_list(list, "%d");

    test_expr("should remove the last element", *p == 4);
    test_expr("should have a size of 3", list->size == 3);

    linkedlist_destroy(list);
}