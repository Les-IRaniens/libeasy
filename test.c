#include <string/string.h>
#include <stdio.h>

int 
main(void)
{
	String str;
	int i;

	init_string(&str);
	
	for (i = 0; i < 10; i++)
	{
		push_char_string(&str, 'a');
	}

	printf("%s\n", as_str_string(&str));
	clear_string(&str);

	for (i = 0; i < 10; i++)
	{
		push_char_string(&str, 'b');
	}

	printf("%s\n", as_str_string(&str));
	return 0;


}