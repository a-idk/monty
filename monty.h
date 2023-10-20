#ifndef _MONTY_H_
#define _MONTY_H_

/* include the header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

#define  _POSIX_C_SOURCE 200809L

/* custom defined structures/varibles types */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct contain_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @flag_d: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct contain_s
{
	char *arg;
	FILE *file;
	char *content;
	int flag_d;
}  contain_t;

extern contain_t contain;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*************PROTOTYPES********************/
void push_node(stack_t **head, unsigned int number);
void print_all_stack(stack_t **head, unsigned int number);
void print_top_stack(stack_t **head, unsigned int number);
int exec(char *content, stack_t **head, unsigned int num, FILE *file);
void free_dstack(stack_t *head);
void pop_stack(stack_t **head, unsigned int num);
void swap_top(stack_t **head, unsigned int num);
void rotate_to_top(stack_t **head, unsigned int num);
void rotate_to_bottom(stack_t **hd, __attribute__((unused)) unsigned int num);
void node_adder(stack_t **hd, int n);
void enqueue(stack_t **head, int n);
void add_stack(stack_t **head, unsigned int num);
void nop_stack(stack_t **hd, unsigned int num);
void sub_stack(stack_t **head, unsigned int num);
void div_opcode(stack_t **head, unsigned int num);
void mul_opcode(stack_t **head, unsigned int num);
void mod_opcode(stack_t **head, unsigned int num);
void print_top_char(stack_t **head, unsigned int num);
void print_top_str(stack_t **head, unsigned int num);
void queue_func(stack_t **hd, unsigned int nm);
void data_stack(stack_t **hd, unsigned int nm);


#endif /* main.h */
