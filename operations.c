#include "monty.h"

/**
 * _sub - A function that subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to head of list
 * @line_number: currrent line
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(5, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}
/**
 * _div - divides the second top element of the stack by the
 * top element of the stack.
 * @stack: pointer to top of stack list
 * @line_number: current working line
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(6, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}

/**
 * _mul - a function that multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: pointer to top of stack list
 * @line_number: current working line
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(8, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}

/**
 * _mod - afunction that computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to top od stack list
 * @line_number: current working line
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(9, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}
