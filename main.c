#include "monty.h"

/**
*main - entry point for stacks and queues
*@argc: argument count
*@argv: argument vector
*Return: 0 on success else number
*/
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	list_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	get_file(argv[1]);

	temp = list_opcode;

	for (; temp; temp = temp->next)
		(*ptr_opcode(temp))(&stack, temp->n);

	free_all(list_opcode, stack);
	return (0);
}
