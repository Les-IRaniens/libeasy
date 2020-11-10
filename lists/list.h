#ifndef _LIBEASY_LIST_H_
#define _LIBEASY_LIST_H_

#include <stdbool.h>
#include <stddef.h>
#include "types.h"

#define LIST_DEFAULT_CAPACITY 32

typedef struct _Element
{
    void *ptr;
    Type type;
} Element;

typedef struct _List 
{
    Element *array;
    size_t length;
    size_t capacity;
} List;

void init_list(List *);
void free_list(List *);
void append_list(List *, void *, Type);
size_t len_list(List *);
char *as_str_list(List *);
Element get_list_element(List *, size_t);

#endif /* !_LIBEASY_LIST_H_ */