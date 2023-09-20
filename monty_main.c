#include "monty.h"

/**
 * main - Entry point function for monty interpreter
 * @ac: number of arguments
 * @av: The pointer to an array arguments
 * Return: Always 0 (on success)
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	int exit_status = EXIT_SUCCESS;

	if (ac != 2)
		return (usage_error(1));

	fd = fopen(av[1], "r");
	if (fd == NULL)
		return (open_error(av[1]));

	exit_status = monty_run(fd);
	fclose(fd);
	return (exit_status);
		open_error(av[1]);
	monty_run(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
