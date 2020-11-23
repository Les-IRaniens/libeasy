#define _GNU_SOURCE

#include "string.h"

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void 
init_string(String *self)
{
    self->buffer = (char *) malloc(STRING_DEFAULT_CAPACITY);
    assert(self->buffer != NULL);

    self->capacity = STRING_DEFAULT_CAPACITY;
    self->length = 0;
}

void 
free_string(String *self)
{
    free(self->buffer);
    self->capacity = 0;
    self->length = 0;
}

void 
push_char_string(String *self, char c)
{

    if (self->length + 1 == self->capacity)
    {
        self->capacity *= 1.25;
        self->buffer = (char *) realloc(self->buffer, self->capacity);

        assert(self->buffer != NULL);
    }

    self->buffer[self->length++] = c;
    self->buffer[self->length] = '\0';
}

void 
push_str_string(String *self, const char *s)
{
    size_t i;

    for (i = 0; i < strlen(s); i++)
    {
        push_char_string(self, s[i]);
    }
}

void
push_format_string(String *self, const char *format, ...)
{
    char buffer[1024];
    va_list va;

    va_start(va, format);

    vsnprintf(buffer, (size_t) 1024, format, va);
    push_str_string(self, buffer);

    va_end(va);
}

void 
clear_string(String *self)
{
    memset(self->buffer, 0, self->length);
    self->length = 0;
}

char *
as_str_string(String *self)
{
    return self->buffer;
}

size_t 
len_string(String *self)
{
    return self->length;
}

void 
pop_tovoid_char_string(String *self, size_t amount)
{
    size_t i;

    for(i = len_string(self)-amount; i < len_string(self); i++)
    {
        self->buffer[i] = '\0';
    }

    self->length -= amount;
}

