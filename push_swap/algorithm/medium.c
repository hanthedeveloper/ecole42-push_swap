/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:51:56 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 19:50:30 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static int	find_max_pos(t_linkedlist *stack)
{
	t_linkedlist	*head;
	int				max;
	int				max_pos;
	int				pos;

	head = stack;
	max = stack->rank;
	max_pos = 0;
	pos = 0;
	while (pos == 0 || stack != head)
	{
		if (stack->rank > max)
		{
			max = stack->rank;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	push_max_to_a(t_linkedlist **a, t_linkedlist **b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_pos(*b);
	size = ft_lstsize(*b);

	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rb(b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < size)
		{
			rrb(b);
			max_pos++;
		}
	}
	pa(b, a);
}

void	medium(t_linkedlist **a, t_linkedlist **b)
{
	int	chunk_size;
	int	i;
	int	size;

	size = ft_lstsize(*a);
	chunk_size = ft_sqrt(size);
	i = 0;
	while (*a) // 0,1,2  3,4,5 
	{
		if ((*a)->rank <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->rank <= i + chunk_size)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
		push_max_to_a(a, b);
}