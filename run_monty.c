#include "monty.h"
#include <stdio.h>
/**
 * monty_run - A function that runs Monty Bytcodes Script
 * @fd: File descriptor for an open Monty Bytcode script
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */

int monty_run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	unsigned int line_num = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		if (empty_line(line, delim))
			continue;
		token = tokening(line, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			exit_status = monty_push(&stack, token, line_num);
		else
			exit_status = execute(token, &stack, line_num);
		free(token);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(line);
	return (exit_status);
}


/**
 * empty_line - A function that checks if a line contains only delimeters
 * @line: The pointer to line to be checked
 * @delims: The string with delimeters characters
 * Return: 1 if ine contains delimiters, otherwise 0
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
