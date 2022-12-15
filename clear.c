#include "monty.h"
/**
*_free - function that frees a list
*@stack: pointer to list
*/
void _free(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}
/**
*clear - function that frees list and closes file
*@stack: pointer to list
*/
void clear(stack_t **stack)
{
	_free(stack);
	fclose(global.fd);
}
