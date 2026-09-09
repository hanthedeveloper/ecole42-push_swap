
// BITTI 

#include "push_swap.h"

void	reverse_rotate(t_linkedlist **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_linkedlist **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_linkedlist **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_linkedlist **a, t_linkedlist **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
