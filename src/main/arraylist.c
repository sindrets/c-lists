#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int size;
    char **data;
} ArrayList;

ArrayList *arraylist_create()
{
    ArrayList *list = malloc(sizeof(*list));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->data = malloc(sizeof(void*));
    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    return list;
}

void arraylist_destroy(ArrayList *list)
{
    free(list->data);
    free(list);
}

void *arraylist_get(ArrayList *list, unsigned int index)
{
    if (index >= list->size) {
        return NULL;
    }

    return list->data[index];
}

void arraylist_insert(ArrayList *list, void *element, unsigned int index)
{
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = element;
    list->size++;
    list->data = realloc(list->data, (list->size + 1) * sizeof(void*));
}

void *arraylist_insert_alloc(ArrayList *list, void *element, unsigned int elmntSize, unsigned int index)
{
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = malloc(elmntSize);
    memcpy(list->data[index], element, elmntSize);
    list->size++;
    list->data = realloc(list->data, (list->size + 1) * sizeof(void*));

    return list->data[index];
}

void arraylist_push(ArrayList *list, void *element)
{
    arraylist_insert(list, element, list->size);
}

void *arraylist_push_alloc(ArrayList *list, void *element, unsigned int elmntSize)
{
    return arraylist_insert_alloc(list, element, elmntSize, list->size);
}

void *arraylist_remove(ArrayList *list, unsigned int index)
{
    if (index >= list->size) {
        return NULL;
    }

    void *target = list->data[index];
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    
    list->size--;
    list->data = realloc(list->data, (list->size + 1) * sizeof(void*));

    return target;
}

void *arraylist_pop(ArrayList *list)
{
    return arraylist_remove(list, list->size - 1);
}

void arraylist_print(ArrayList *list, char* format)
{
    printf("<ArrayList [");
    for (int i = 0; i < list->size; i++) {
        printf(format, *(int*)list->data[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]>");
}

#endif