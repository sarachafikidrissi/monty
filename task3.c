#include "monty.h"

/**
 * monty_swap - A function that swaps the top two elements of the stack.
 * @stack: pointer to top of stack list
 * @line_number: the current working line
 * Return: Nothing
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(3, line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}
