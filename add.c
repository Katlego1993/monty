#include "monty.h"
/**
 * f_add - addd stack of the two top element
 * @head: head stack
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux = hd->n + hd->next->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}
