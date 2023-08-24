#include "monty.h"
/**
 * f_div - divides two top stack element
 * @head: head of stack
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = hd->next->n / hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}
