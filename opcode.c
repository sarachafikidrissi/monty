#include "monty.h"

/**
 * execute - a function that checks for command and execute
 * function if there is a match
 * @token: token containing opcode to execute
 * @stack: doubly linked list representation of stack
 * @line_num: Line number where the opcode was found
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int execute(char **token, stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", _add},
		{"mod", _mod},
		{"mul"_mul},
		{"div", _div},
		{"sub", _sub},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_num, token[0]);
	return (EXIT_FAILURE);
}

/**
 * monty_push - A function that insert an element to stack
 * @stack: pointer to stack struct
 * @token: pointer to command
 * @line_num: number of line
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */

int monty_push(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new;
	int i = 0;

	if (token[1] == NULL)
		return (f_errors(0, line_num));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (f_errors(0, line_num));
		}
		i++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage_error(0));

	new->n = atoi(token[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}
/**
 * monty_pall - a function that prints stack data
 * @stack: pointer to top of stack_t
 * @line_num: number of line
 * Return: Nothing
 */
void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * monty_pint - A function that print the value at the top of stack
 * @stack: pointer to stack list
 * @line_number: current working line in monty bytecode
 * Return: Nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(1, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}
