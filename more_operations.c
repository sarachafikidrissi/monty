#include "monty.h"

/**
 * _pchar - fucntion that prints the char at the top of the stack
 * of the stack, followed by a new line.
 * @stack: pointer to the top of stack list
 * @line_number: the current working line
 * Return: Nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(11, line_number);
		exit(EXIT_FAILURE);
	}
	number = tmp->n;
	if (number < 0 || number > 127)
	{
		f_errors(10, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * _pstr - a function that prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack: pointer to the top of stack list
 * @line_number: the current working line
 * Return: Nothing
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n > 0 && tmp->n <= 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		else
			break;
	}
	printf("\n");
}
