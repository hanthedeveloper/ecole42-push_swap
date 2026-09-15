/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:39:54 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 17:57:59 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"

static int	compare_bits(t_linkedlist *stack, int i)
{
	int				result;

	if (!stack)
		return (-1);
	if ((stack->rank >> i) & 1)
		result = 1;
	else
		result = 0;
	return (result);
}

static void	find_maxrank(t_linkedlist *stack, int *max_rank)
{
	t_linkedlist	*cur;

	*max_rank = stack->rank;
	cur = stack->next;
	while (cur != stack)
	{
		if (cur->rank > *max_rank)
			*max_rank = cur->rank;
		cur = cur->next;
	}
}

int	howmany_bits(int max_rank)
{
	int	max_bit;

	max_bit = 0;
	while ((max_rank >> 1) != 0)
	{
		max_rank = max_rank >> 1;
		max_bit++;
	}
	return (max_bit);
}

void	complex(t_linkedlist **a, t_linkedlist **b)
{
	int	i;
	int	size;
	int	j;
	int	max_rank;
	int	bit_length;

	i = 0;
	size = ft_lstsize(*a);
	find_maxrank(*a, &max_rank);
	bit_length = howmany_bits(max_rank);
	while (i <= bit_length)
	{
		j = 0;
		while (j < size)
		{
			if (!compare_bits(*a, i))
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(b, a);
		i++;
	}
}
