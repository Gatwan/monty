#include "monty.h"
/**
*length - function that returns no of elements in an array
*@c: array
*Return: number of elements
*/
int length(char **c)
{
	int i = 0;

	while (c[i])
	{
		i++;
	}
	return (i);
}
