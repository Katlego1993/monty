#include "monty.h"
/**
 * f_mul - top two elements of stack multiplier
 * @head: head of stack
 * @counter: line_number
 * Return: non
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int l = 0, aux;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux = hd->next->n * hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}
