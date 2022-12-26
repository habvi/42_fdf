#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

void    error_and_exit(const char *msg, char *ptr, int status)
{
	printf("Error: %s\n", msg);
    if (ptr)
	    free(ptr);
	exit (status);
}
