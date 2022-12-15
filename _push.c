#include "monty.h"
/**
*push - function that pushes nodes in the stack
*@stack: pointer to stack structure
*@line_number: Number of instructions
*/
void push(stack_t **stack, unsigned int line_number)
{
	core_stack_queue(stack, line_number, 0);
}

/**
*stack - function that pushes nodes in the stack
*@stack: pointer to stack structure
*@line_number: number of instructions
*/
void stack(stack_t **stack, unsigned int line_number)
{
	core_stack_queue(stack, line_number, 1);
}

/**
*queue - function that pushes nodes in the queue
*@stack: pointer to stack structure
*@line_number: number of instructions
*/
void queue(stack_t **stack, unsigned int line_number)
{
	core_stack_queue(stack, line_number, 2);
}
