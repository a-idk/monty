/* Main */

#include "monty.h"

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
/*	contain_t contain = {NULL, NULL, NULL, 0};*/
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
