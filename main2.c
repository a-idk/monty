#include "monty.h"

contain_t contain = {NULL, NULL, NULL, 0};

/**
* exec - function that executes the opcode called from the main function
* @stack: head of stack
* @num: line nos.
* @file: poiner to monty file
* @content: line content
* Return: no return
*/

int exec(char *content, stack_t **stack, unsigned int num, FILE *file)
{
	/* Declaring variables */
	unsigned int idx = 0;
	char *com;

	/* setting the instructions */
	instruction_t opst[] = {
		{"push", push_node}, {"pall", print_all_stack},
		{"pint", print_top_stack}, {"pop", pop_stack},
		{"swap", swap_top}, {"add", add_stack},
		{"nop", nop_stack}, {"sub", sub_stack},
		{"div", div_opcode}, {"mul", mul_opcode},
		{"mod", mod_opcode}, {"pchar", print_top_char},
		{"pstr", print_top_str}, {"rotl", rotate_to_top},
		{"rotr", rotate_to_bottom}, {"queue", queue_func},
		{"stack", data_stack}, {NULL, NULL}
	};
	com = strtok(content, " \n\t");
	if (com && (com[0] == '#'))
		return (0);
	contain.arg = strtok(NULL, " \n\t");
	while ((opst[idx].opcode) && com)
	{
		if (strcmp(com, opst[idx].opcode) == 0)
		{	opst[idx].f(stack, num);
			return (0);
		}
		idx = idx + 1;
	}
	if (com && opst[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", num, com);
		fclose(file), free(content), free_dstack(*stack), exit(EXIT_FAILURE);
	}
	return (1);
}
