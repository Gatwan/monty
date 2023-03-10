#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
*struct stack_s - doubly linked list representation of a stack (or queue)
*@n: integer
*@prev: points to the previous element of the stack (or queue)
*@next: points to the next element of the stack (or queue)
*
*Description: doubly linked list node structure
*for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
*struct instruction_s - opcode and its function
*@opcode: the opcode
*@f: function to handle the opcode
*
*Description: opcode and its function
*for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
*struct glob_s - global and its funcs
*@fd: File descriptor
*@line: line to getline
*@element: element to be added
*
*Description: to check the file and getline
*/
typedef struct glob_s
{
	FILE *fd;
	char *line;
	int element;
} glob_t;

extern glob_t global;


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void _div(stack_t **stack, unsigned int linenumber);
void mul(stack_t **stack, unsigned int linenumber);
void rotr(stack_t **stack, unsigned int line_number);

void exec_cmd(char **command, unsigned int line_number, stack_t **head);
char **parser(char *buff);
int length(char **c);
int str_cmp(char *str1, char *str2);
int is_digit(char *c);
void _free(stack_t **stack);
void clear(stack_t **stack);
int check_arg(char **argument);

#endif
