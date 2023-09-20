#include "monty.h"

/**
 * free_stack - A function that frees the memory allocated to stack
 * @stack: Pointer to stack
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
