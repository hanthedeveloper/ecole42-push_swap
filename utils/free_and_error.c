

#include "utils.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_stack(t_linkedlist **stack)
{
	t_linkedlist	*current;
	t_linkedlist	*next;
	t_linkedlist	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	(*stack)->prev->next = NULL;
	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ft_free_exit(t_linkedlist **a, t_linkedlist **b)
{
	free_stack(a);
	free_stack(b);
	error();
}
