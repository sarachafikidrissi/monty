#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/*===========================================*/
/*============  Opcode Functions ============*/
/*===========================================*/

int main(int ac, char **av);

int monty_run(FILE *fd);
char **tokening(char *line, char *delim);
int empty_line(char *line, char *delims);

int execute(char **token, stack_t **stack, unsigned int line_num);
int monty_push(stack_t **stack, char **token, unsigned int line_num);
void monty_pall(stack_t **stack, unsigned int line_num);





/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#endif
