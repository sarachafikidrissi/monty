#include "monty.h"

/**
 * _add - A function that adds the top two elements of the stack.
 * @stack: head of the linked list
 * @line_number: current working line  number
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(4, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}
