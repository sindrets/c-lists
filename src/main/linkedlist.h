#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _Node {
    void *item;
    struct _Node *prev;
    struct _Node *next;
} Node;

typedef struct {
    unsigned int size;
    Node *first;
    Node *last;
} LinkedList;

LinkedList *linkedlist_create();

void linkedlist_destroy(LinkedList *list);

void linkedlist_insert(LinkedList *list, void *element, unsigned int pos);

void linkedlist_push(LinkedList *list, void *element);

void linkedlist_set(LinkedList *list, void *element, unsigned int pos);

void *linkedlist_get(LinkedList *list, unsigned int pos);

void *linkedlist_remove(LinkedList *list, void *element);

void *linkedlist_remove_pos(LinkedList *list, unsigned int pos);

void *linkedlist_pop(LinkedList *list);

void linkedlist_print(LinkedList *list, char* format);

#endif