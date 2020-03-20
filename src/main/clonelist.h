#ifndef CLONELIST_H
#define CLONELIST_H

typedef struct {
    unsigned int size;
    unsigned int elmntSize;
    char **data;
} CloneList;

CloneList *clonelist_create(unsigned int elmntSize);

void clonelist_destroy(CloneList *list);

void *clonelist_get(CloneList *list, unsigned int index);

void *clonelist_insert(CloneList *list, void *element, unsigned int index);

void *clonelist_remove(CloneList *list, unsigned int index);

void *clonelist_push(CloneList *list, void *element);

void *clonelist_pop(CloneList *list);

void *clonelist_print(CloneList *list, char *format);

#endif