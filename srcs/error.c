#include <stdio.h>
#include <stdlib.h>

void exit_error(char *str)
{
	perror(str);
	exit(-1);
}