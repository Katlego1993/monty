#include "monty.h"
/**
 * f_mod - second top element of stack computes by top element stack
 * @head: head of stack
 * @counter: line_number
 * Return: non
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int l = 0, aux;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		l++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = hd->next->n % hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}

