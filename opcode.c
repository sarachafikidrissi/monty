#include "monty.h"

void push(int x)
{
	stack_t *newnode;
	newnode = malloc(sizeof(stack_t));

	if (new_node == NULL)
		fprintf(stderr, "Error: malloc failed");
