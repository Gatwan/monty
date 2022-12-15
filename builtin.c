#include "monty.h"
/**
*push - adds element to the stack
*@stack: pointer to list
*@line_number: line to being executes
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		clear(stack);
		exit(EXIT_FAILURE);
	}

	new->n = global.element;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;

	if (new->next != NULL)
		new->next->prev = new;
}
/**
*pall - prints all elements in the list
*@line_number: line number being executed
*@stack: pointer to list
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
*pint - prints top element on stack
*@stack: pointer to list
*@line_number: line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*pop - removes top element
*@stack: pointer to list
*@line_number: line to being executed
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);		clear(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = current->next;
		if (*stack)
			(*stack)->prev = NULL;
	}
	free(current);
}
/**
*nop - does nothing
*@stack: pointer to list
*@line_number: line to be executed
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
