/* Main */

#include "monty.h"

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


/* contain_t contain = {NULL, NULL, NULL, 0};*/
/**
* main - entry point for  the monty code interpreter
* @arg_c: arguments count
* @arg_v: argument vector
* @a_idk scripting
*
* Return: Always 0 (Success!)
*/

int main(int arg_c, char *arg_v[])
{
	/* declaring and inititalizing variables */
	contain_t contain = {NULL, NULL, NULL, 0};
	char *content;
	FILE *fd;
	size_t size = 0;
	ssize_t line_rd = 1;
	stack_t *stack = NULL;
	unsigned int num = 0;

	if (arg_c != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(arg_v[1], "r"), contain.file = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg_v[1]);
		exit(EXIT_FAILURE);
	}
	/* else */
	while (line_rd > 0)
	{
		content = NULL, line_rd = getline(&content, &size, fd);
		contain.content = content, num += 1;
		if (line_rd > 0)
			exec(content, &stack, num, fd);
		free(content);
	}
	free_dstack(stack), fclose(fd);
	return (0);
}
