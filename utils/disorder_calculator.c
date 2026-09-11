#include "utils.h"

double	disorder_calculator(t_linkedlist *stack)
{
	t_linkedlist	*head;
	t_linkedlist	*prev;
	t_linkedlist	*temp;
	int				mistakes;
	int				total_pairs;

	if (!stack || stack->next == stack)
		return (0);
	head = stack;
	mistakes = 0;
	total_pairs = 0;
	prev = stack;
	do
	{
		temp = prev->next;
		while (temp != head)
		{
			total_pairs++;
			if (prev->data > temp->data)
				mistakes++;
			temp = temp->next;
		}
		prev = prev->next;
	}
	while (prev != head);
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}