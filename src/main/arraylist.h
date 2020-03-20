#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
    unsigned int size;
    void **data;
} ArrayList;

/**
 * Creates a new ArrayList.
 * @returns A pointer to the new list.
 */
ArrayList *arraylist_create();

/**
 * Destroy an ArrayList and free its memory.
 * @param list The list to destroy.
 */
void arraylist_destroy(ArrayList *list);

/**
 * Retrieve an element from the list.
 * @param list The list
 * @param index Index of the target element
 * @returns Pointer to the element
 */
void *arraylist_get(ArrayList *list, unsigned int index);

/**
 * Insert an element into an ArrayList on a given index.
 * @param list The list
 * @param element The element pointer
 * @param index The insertion index
 */
void arraylist_insert(ArrayList *list, void *element, unsigned int index);

/**
 * Allocate memory for an element and insert into the list at a given index.
 * @param list The list
 * @param element The element pointer
 * @param elmntSize Number of bytes to allocate for this element
 * @param index The insertion index
 * @returns The pointer to the allocated memory.
 */
void *arraylist_insert_alloc(ArrayList *list, void *element, unsigned int elmntSize, unsigned int index);

/**
 * Append an element to the end of the list.
 * @param list The list
 * @param element The element pointer
 */
void arraylist_push(ArrayList *list, void *element);

/**
 * Allocate memory for an element and append it to the end of the list.
 * @param list The list
 * @param element The element pointer
 * @param elmntSize Number of bytes to allocate for this element.
 */
void *arraylist_push_alloc(ArrayList *list, void *element, unsigned int elmntSize);

/**
 * Remove and return the last element from the list.
 * @param list The list
 * @returns Pointer to the last element in the list
 */
void *arraylist_pop(ArrayList *list);

/**
 * Remove an element from the list.
 * @param list The list
 * @param index Index of the target element
 * @returns Pointer to the removed element
 */
void *arraylist_remove(ArrayList *list, unsigned int index);

/**
 * Print a string representation of the list.
 * @param list The list
 * @param format The string passed to printf
 */
void arraylist_print(ArrayList *list, char* format);

#endif