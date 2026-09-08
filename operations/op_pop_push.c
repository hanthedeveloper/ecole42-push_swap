// BU DA BITTI :D

#include "push_swap.h"

/* pop the first element at the top of the first given stack called "from",
and push it at the top of the second stack called "to".
do nothing if "from" stack is empty. */
static void	move(t_linkedlist **from, t_linkedlist **to)
{
	int	data;

	if (!*from)
		return ;
	data = pop(from);
	push(data, to);
}

/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty */
void	pa(t_linkedlist **b, t_linkedlist **a)
{
	move(b, a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_linkedlist **a, t_linkedlist **b)
{
	move(a, b);
	ft_putendl_fd("pb", 1);
}