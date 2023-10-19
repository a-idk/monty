/* Rotl */

#include "monty.h"

/**
 * rotate_to_top- function/opcode that rotates the stack to the top
 * @hd: head of stack
 * @num: line no.
 * @a_idk scripting
 *
 * Return: no return
 */

void rotate_to_top(stack_t **hd,  __attribute__((unused)) unsigned int num)
{
	/* variable declaration and definition */
	stack_t *temp;
	stack_t *tmp = *hd;

	if (((*hd)->next == NULL) || (*hd == NULL))
		return;
	temp = (*hd)->next, temp->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *hd, (*hd)->next = NULL, (*hd)->prev = tmp, (*hd) = temp;
}


/* Rotr */

/**
  * rotate_to_bottom- function that rotates the stack to the bottom
  * @hd: head of stack
  * @num: line no.
  * @a_idk scripting
  *
  * Return: NADA!
 */

void rotate_to_bottom(stack_t **hd, __attribute__((unused)) unsigned int num)
{
	/* declaring and defining variable */
	stack_t *cp;

	cp = *hd;
	if (*hd == NULL || (*hd)->next == NULL)
		return;
	while (cp->next)
		cp = cp->next;
	cp->next = *hd, cp->prev->next = NULL, cp->prev = NULL;
	(*hd)->prev = cp, (*hd) = cp;
}


/* Stack */

/**
 * data_stack - function that sets the format of the data to a stack (LIFO)
 * @hd: head of stack
 * @nm: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void data_stack(stack_t **hd, unsigned int nm)
{
	/* declaring and defining the variables*/
	(void)nm;
	(void)hd;

	contain.flag_d = 0;

}


/* Queue */

/**
 * queue_func - function that sets the format of the data to a queue
 * @hd: head of stack
 * @nm: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void queue_func(stack_t **hd, unsigned int nm)
{
	(void)nm;
	(void)hd;

	contain.flag_d = 1;
}

/**
 * enqueue - functin that adds node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * @a_idk scripting
 *
 * Return: NADA!
*/

void enqueue(stack_t **head, int n)
{
	/* declaring and defining variable */
	stack_t *temp = *head;
	stack_t *n_elem;

	/* allocating dynamic memory */
	n_elem = malloc(sizeof(stack_t));
	if (n_elem == NULL)
		printf("Error\n");
	n_elem->n = n, n_elem->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
		*head = n_elem, n_elem->prev = NULL;
	else
		temp->next = n_elem, n_elem->prev = temp;
}
