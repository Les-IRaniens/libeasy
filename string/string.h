#ifndef _LIBEASY_STRING_H_
#define _LIBEASY_STRING_H_ 

#include <stddef.h>

#define STRING_DEFAULT_CAPACITY 32

typedef struct _String 
{
    char *buffer;
    size_t capacity;
    size_t length;
} String;

void init_string(String *);
void free_string(String *);

void push_char_string(String *, char);
void push_string(String *, const char *, ...);
size_t len_string(String *);
char *as_str_string(String *);
void pop_tovoid_char_string(String *, size_t);

#endif /* !_LIBEASY_STRING_H_ */