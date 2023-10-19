/* Div */

#include "monty.h"
/**
 * div_opcode - function that divides the asecond top element of the stack
 * by the top element of the stack.
 * @head: head of stack
 * @num: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void div_opcode(stack_t **head, unsigned int num)
{
	/* declaring and defining variables */
	int temp;
	stack_t *tp;
	int length = 0;

	tp = *head;
	while (tp != NULL)
		tp = tp->next, length += 1;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	if (tp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num), fclose(contain.file);
		free(contain.content), free_dstack(*head), exit(EXIT_FAILURE);
	}
	temp = tp->next->n / tp->n, tp->next->n = temp, *head = tp->next, free(tp);
}

/* Mul */

/**
 * mul_opcode - function that multiplies the second top element of the stack
 * with the top element of the stack
 * @head: head of stack
 * @num: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void mul_opcode(stack_t **head, unsigned int num)
{
	/* declaring and defining variables */
	int temp;
	stack_t *tp;
	int length = 0;

	tp = *head;
	while (tp != NULL)
		tp = tp->next, length += 1;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head, temp = tp->next->n * tp->n, tp->next->n = temp;
	*head = tp->next, free(tp);
}

/* Mod */

/**
 * mod_opcode - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @head: head of stack
 * @num: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void mod_opcode(stack_t **head, unsigned int num)
{
	/* declaring and defining variables */
	int temp;
	stack_t *tp;
	int length = 0;

	tp = *head;
	while (tp)
		tp = tp->next, length += 1;
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}
	tp = *head;
	if (tp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num), fclose(contain.file);
		free(contain.content), free_dstack(*head), exit(EXIT_FAILURE);
	}
	temp = tp->next->n % tp->n, tp->next->n = temp, *head = tp->next, free(tp);
}

/* pchar */

/**
 * print_top_char - function that prints the char at the top of the
 * stack, followed by a new line
 * @head: head of stack
 * @num: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void print_top_char(stack_t **head, unsigned int num)
{
	/* declaring variable */
	stack_t *h;

	h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}
	if ((h->n > 127) || (h->n < 0))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		fclose(contain.file), free(contain.content), free_dstack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);

}

/* Pstr */

/**
 * print_top_str - function that prints the string starting at the top of
 * the stack, followed by a new
 * @head: head of stack
 * @num: line no.
 * @a_idk scripting
 *
 * Return: NADA!
*/

void print_top_str(stack_t **head, unsigned int num)
{
	/* declaring and defining variables */
	stack_t *tp = *head;
	(void)num;

	while (tp != NULL)
	{
		if ((tp->n > 127) || (tp->n <= 0))
			break;
		printf("%c", tp->n), tp = tp->next;
	}
	/* print next line */
	printf("\n");
}
