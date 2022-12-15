#include "monty.h"
/**
*check_arg - checks if command exists
*@argument: array of commands
*Return: 0 if true else -1
*/
int check_arg(char **argument)
{
	int i = 0;
	char *array[] = {"push", "pall", "pint", "pop", "nop", "swap",
	"add", "sub", "div", "mul", "mod", "pchar", "pstr", "rot1", "rotr", NULL};

	while (array[i])
	{
		if (strcmp(array[i], argument[0]) == 0)
			return (0);
		i++;
	}
	return (-1);
}
