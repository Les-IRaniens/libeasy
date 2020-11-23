#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "list.h"
#include "types.h"

#include "string/string.h"

void 
init_list(List *self)
{
	self->array = (Element *) malloc(sizeof(Element) * LIST_DEFAULT_CAPACITY);
	assert(self->array != NULL);

	self->capacity = LIST_DEFAULT_CAPACITY;
	self->length = 0;
}

void 
free_list(List *self)
{
	size_t i;
	Element list_element;

	for (i = 0; i < len_list(self); i++)
	{
		list_element = get_list_element(self, i);

		if (list_element.type == CHAR_PTR_MALLOC)
		{
			free(list_element.ptr);
		}
	}

	free(self->array);
	self->capacity = 0;
	self->length = 0;
}

void 
append_list(List *self, void *list_element, Type type)
{
	Element elem;

	if (self->length == self->capacity) 
	{
		self->capacity *= 1.25;

		self->array = (Element *) realloc(self->array, self->capacity);
		assert(self->array != NULL);
	}

	elem.ptr = list_element;
	elem.type = type;

	self->array[self->length++] = elem;
}

size_t
len_list(List *self)
{
	return self->length;
}

Element 
get_list_element(List *self, size_t index)
{
	return self->array[index];
}

char *
as_str_list(List *self)
{
	size_t i;
	Element current;
	String str;

	init_string(&str);

	push_format_string(&str, "[ ");

	for (i = 0; i < len_list(self); i++)
	{
		current = get_list_element(self, i);

		switch (current.type)
		{
			case CHAR:
			/* FALLTROUGH */
			case CHAR_PTR:
			/* FALLTROUGH */
			case CHAR_PTR_MALLOC:
				push_format_string(&str, "%s, ", (char *) current.ptr);
				break;

			case FLOAT:
				push_format_string(&str, "%.2f, ", *((float *) current.ptr));
				break;

			case DOUBLE:
				push_format_string(&str, "%.2f", *((double *) current.ptr));
				break;

			case INT:
				push_format_string(&str, "%d, ", *((int *) current.ptr));
				break;

			case LONG:
				push_format_string(&str, "%ld, ", *((long *) current.ptr));
				break;

			default:
				/* TYPE MANQUANT ! */
				assert(0);
			}
	}

	pop_tovoid_char_string(&str, 2);
	push_format_string(&str, " ]");
	return as_str_string(&str);
}