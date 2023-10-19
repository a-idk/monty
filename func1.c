#include "monty.h"

/**
 * node_adder - function that adds a node to the begining
 * or head of the stack
 * @hd: head of stack
 * @n: value to be added
 * @a_idk scripting
 *
 * Return: no return
*/

void node_adder(stack_t **hd, int n)
{
	/* declaring the variables */
	stack_t *temp;
	stack_t *n_elem; /* new element / node */

	/* defining the temp */
	temp = *hd;
	/* allocating dynamic memory */
	n_elem = malloc(sizeof(stack_t));
	/* checking for NULL value */
	if (n_elem == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (temp != NULL)
		temp->prev = n_elem;
	n_elem->n = n, n_elem->next = *hd, n_elem->prev = NULL, *hd = n_elem;
}


/**
* free_dstack - function that frees doubly linked list
* @hd: head of the stack
* @a_idk scripting
*
* Return: NADA!
*/

void free_dstack(stack_t *hd)
{
	/* declaring variable */
	stack_t *temp;

	temp = hd;
	while (hd != NULL)
		temp = hd->next, free(hd), hd = temp;
}


/**
 * push_node - function that adds node to current stack
 * @head: stack head
 * @num: line_number
 * @a_idk scripting
 *
 * Return: NADA!
*/

void push_node(stack_t **head, unsigned int num)
{
	/* declaring and defining variable */
	int fg = 0; /* flag */
	int store;
	int indx = 0;

	if (contain.arg)
	{
		if (contain.arg[0] == '-')
			indx += 1;
		for (; contain.arg[indx] != '\0'; indx += 1)
		{
			if ((contain.arg[indx] < 48) || (contain.arg[indx] > 57))
				fg = 1;
		}
		if (fg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(contain.file), free(contain.content), free_dstack(*head);
			exit(EXIT_FAILURE);
		}
	} else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num), fclose(contain.file);
		free(contain.content), free_dstack(*head), exit(EXIT_FAILURE);
	}
	store = atoi(contain.arg);
	if (contain.flag_d == 0)
		node_adder(head, store);
	else
		enqueue(head, store);
}


/* 2. Pall */

/**
 * print_all_stack - function that prints all the values on the stack
 * starting from the top of the stack
 * @head: head of the stack
 * @num: value to be used
 * @a_idk scripting
 *
 * Return: NADA!
*/

void print_all_stack(stack_t **head, unsigned int num)
{
	/* declaring variables */

	stack_t *top;
	(void)num;

	top = *head;
	/* check for NULL */
	if (top == NULL)
	{
		return;
	}
	while (top != NULL)
		printf("%d\n", top->n), top = top->next;
}

/* Pint */

/**
 * print_top_stack - function that prints the top of the stack
 * @hd: head of stack
 * @num: current line number
 * Return: no return
*/

void print_top_stack(stack_t **hd, unsigned int num)
{
	if (*hd == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*hd);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*hd)->n);

}
