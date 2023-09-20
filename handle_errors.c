#include "monty.h"
/**
 * usage_error - A function that prints usage error message
 * @flag: Type of error
 * Return: EXIT_FAILURE
 */
int usage_error(int flag)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[flag]);
	return (EXIT_FAILURE);
}

/**
 * open_error - a function that prints file open error message
 * @filename: name of the file failed to open
 * Return: EXIT_FAILURE
 */
int open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * f_errors - A fucntion that print the errors
 * @flag: The index to type of error
 * @line_num: number of line that has error
 * Return: EXIT_FAILURE
 */

int f_errors(int flag, unsigned int line_num)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty",
		 "can\'t pop an empty stack", "can\'t swap, stack too short",
		 "can\'t add, stack too short", "can\'t sub, stack too short",
		 "can\'t div, stack too short", "division by zero",
		 "can\'t mul, stack too short", "can\'t mod, stack too short",
		 "can\'t pchar, value out of range", "can\'t pchar, stack empty"};

	fprintf(stderr, "L%d: %s\n", line_num, errors[flag]);
	return (EXIT_FAILURE);
}
