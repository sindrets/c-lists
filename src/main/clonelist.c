#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    unsigned int size;
    unsigned int elmntSize;
    char **data;
} CloneList;

CloneList *clonelist_create(unsigned int elmntSize)
{
    CloneList *list = malloc(sizeof(CloneList));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->elmntSize = elmntSize;
    list->data = malloc(sizeof(char*));
    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    return list;
}

void clonelist_destroy(CloneList *list)
{
    for (int i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
    free(list);
}

void *clonelist_get(CloneList *list, unsigned int index)
{
    if (index >= list->size) {
        return NULL;
    }

    return list->data[index];
}

void *clonelist_insert(CloneList *list, void *element, unsigned int index)
{
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = malloc(list->elmntSize);
    memcpy(list->data[index], element, list->elmntSize);
    list->size++;
    list->data = realloc(list->data, (list->size + 1) * sizeof(char*));

    return list->data[index];
}

void *clonelist_remove(CloneList *list, unsigned int index)
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

void *clonelist_push(CloneList *list, void *element)
{
    return clonelist_insert(list, element, list->size);
}

void *clonelist_pop(CloneList *list)
{
    return clonelist_remove(list, list->size - 1);
}

void clonelist_print(CloneList *list, char* format)
{
    printf("<CloneList [");
    for (int i = 0; i < list->size; i++) {
        printf(format, *(void**)list->data[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]>\n");
}
