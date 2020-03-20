#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

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

LinkedList *linkedlist_create()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

void linkedlist_destroy(LinkedList *list)
{
    Node *cur = list->first;
    for (int i = 1; i <= list->size; i++) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(list);
}

static void *linkedlist_unlink(LinkedList *list, Node *element)
{
    if (list->size > 1) {
        if (element == list->first) {
            list->first = element->next;
            list->first->prev = NULL;
        } else {
            element->prev->next = element->next;
        }

        if (element == list->last) {
            list->last = element->prev;
            list->last->next = NULL;
        } else {
            element->next->prev = element->prev;
        }
    } else {
        list->first = NULL;
        list->last = NULL;
    }

    void *item = element->item;
    free(element);
    list->size--;

    return item;
}

static void *linkedlist_unlink_pos(LinkedList *list, unsigned int pos)
{
    if (pos >= list->size) {
        return NULL;
    }

    Node *cur = list->first;
    for (int i = 1; i <= pos; i++) {
        cur = cur->next;
    }

    return linkedlist_unlink(list, cur);
}

void linkedlist_insert(LinkedList *list, void *element, unsigned int pos)
{
    if (pos > list->size) {
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->item = element;

    if (pos == list->size) {
        newNode->next = NULL;
        newNode->prev = list->last;
        if (list->first == NULL) {
            list->first = newNode;
        } else {
            list->last->next = newNode;
        }
        list->last = newNode;
        list->size++;
        return;
    }

    Node *cur = list->first;
    for (int i = 1; i <= pos; i++) {
        cur = cur->next;
    }

    newNode->prev = cur->prev;
    newNode->next = cur;
    if (newNode->prev != NULL) {
        newNode->prev->next = newNode;
    } else {
        list->first = newNode;
    }
    cur->prev = newNode;
    list->size++;
}

void linkedlist_push(LinkedList *list, void *element)
{
    linkedlist_insert(list, element, list->size);
}

void linkedlist_set(LinkedList *list, void *element, unsigned int pos)
{
    if (pos >= list->size) {
        return;
    }

    Node *cur = list->first;
    for (int i = 1; i <= pos; i++) {
        cur = cur->next;
    }
    cur->item = element;
}

void *linkedlist_get(LinkedList *list, unsigned int pos)
{
    if (pos >= list->size) {
        return NULL;
    }

    Node *cur = list->first;
    for (int i = 1; i <= pos; i++) {
        cur = cur->next;
    }

    return cur->item;
}

void *linkedlist_remove(LinkedList *list, void *element)
{
    if (list->size < 1) {
        return NULL;
    }

    Node *cur = list->first;
    for (int i = 1; i < list->size; i++) {
        if (cur->item == element) {
            break;
        }
        cur = cur->next;
    }
    
    return linkedlist_unlink(list, cur);
}

void *linkedlist_remove_pos(LinkedList *list, unsigned int pos)
{
    return linkedlist_unlink_pos(list, pos);
}

void *linkedlist_pop(LinkedList *list)
{
    return linkedlist_unlink_pos(list, list->size - 1);
}

void linkedlist_print(LinkedList *list, char* format)
{
    printf("<LinkedList [");
    Node *cur = list->first;
    for (int i = 1; i <= list->size; i++) {
        printf(format, *(int*)cur->item);
        if (i < list->size) {
            printf(", ");
        }
        cur = cur->next;
    }
    printf("]>");
}

#endif