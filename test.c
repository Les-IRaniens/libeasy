#include <string/string.h>
#include <lists/list.h>
#include <stdio.h>
#include <stdlib.h>

int 
main(void)
{
	String str;
	String str2;
	String str3;

	List lst;
	List lst2;
	char *dump;

	init_list(&lst);

	init_string(&str);
	init_string(&str2);
	init_string(&str3);

	push_format_string(&str, "abcdef");
	push_format_string(&str2, "Baboushka");
	push_format_string(&str3, "Libeasypz The best lib Ever");
	

	append_list(&lst, &str, STRING);
	append_list(&lst, &str2, STRING);
	append_list(&lst, &str3, STRING);

	dump =  as_str_list(&lst);
	printf("%s\n", dump);
	
	lst2 = split_string(&str3, " "); 
	printf("%s\n", (char *) get_list_element(&lst2, 0).ptr);
	
	free_string(&str);
	free_string(&str2);
	free_string(&str3);

	free_list(&lst);
	free_list(&lst2);

	free(dump);

	return 0;
}