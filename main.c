#include <stdio.h>
#include <stdlib.h>

#include "lists/list.h"

int 
main(void)
{
    List list;
    char *dmp;

    int a = 69;
    char *b = "Coucou";
    float c = 4.20;

    init_list(&list);

    append_list(&list, &a, INT);
    append_list(&list, b, CHAR_PTR);
    append_list(&list, &c, FLOAT);

    dmp = as_str_list(&list);

    printf("%s\n", dmp);

    free_list(&list);
    free(dmp);
    
    return 0;
}