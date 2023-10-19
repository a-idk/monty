/* Pop */

#include "monty.h"
/**
 * pop_stack - function that removes the top
 * @head: head of stack
 * @num: current line number
 * @a_idk scripting
 *
 * Return: NADA!
*/

void pop_stack(stack_t **head, unsigned int num)
{
	/* declaring variable */
	stack_t *tp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head, *head = tp->next, free(tp);
}


/* Swap */

/**
 * swap_top - function that swaps the top two elements of the stack.
 * @hd: stack head
 * @num: number
 * @a_idk scripting
 *
 * Return: NADA!
*/

void swap_top(stack_t **hd, unsigned int num)
{
	/* declaring and defining variable */
	int temp;
	stack_t *h;
	int length = 0;

	h = *hd;
	while (h != NULL)
		h = h->next, length += 1;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*hd);
		exit(EXIT_FAILURE);
	}
	h = *hd, temp = h->n, h->n = h->next->n, h->next->n = temp;
}


/* Add */

/**
 * add_stack - function that adds the top two elements of the stack
 * @hd: head of stack
 * @num: line_number
 * @a_idk scripting
 *
 * Return: NADA!
*/
void add_stack(stack_t **hd, unsigned int num)
{
	/* declare and define variables */
	int temp;
	stack_t *tp;
	int length = 0;

	tp = *hd;
	while (tp != NULL)
	{
		tp = tp->next;
		length += 1;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*hd);
		exit(EXIT_FAILURE);
	}
	tp = *hd, temp = tp->n + tp->next->n, tp->next->n = temp, *hd = tp->next;
	free(tp);
}

/* Nop */

/**
  *nop_stack- function that does nothing to the stack
  *@hd: head of stack
  *@num: line no.
  *Return: no return
 */
void nop_stack(stack_t **hd, unsigned int num)
{
	/* declaring the variable */
	(void) hd;
	(void) num;
}


/* Sub */

/**
  *sub_stack- sustration
  *@head: head of stack
  *@num: line_number
  *@a_idk scripting
  *
  *Return: NADA!
 */

void sub_stack(stack_t **head, unsigned int num)
{
	/* declaring variable */
	stack_t *temp;
	int cont;
	int n_elem;

	/* defining the temp variable */
	temp = *head;
	for (n_elem = 0; temp != NULL; n_elem += 1)
		temp = temp->next;
	/* handling empty stack */
	if (n_elem < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}
	/* else */
	temp = *head, cont = temp->next->n - temp->n, temp->next->n = cont;
	*head = temp->next, free(temp);
}
