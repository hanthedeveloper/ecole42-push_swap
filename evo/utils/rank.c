/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:45:28 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 18:27:24 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	compute_rank(t_linkedlist *stack, t_linkedlist *outer, int size)
{
	t_linkedlist	*inner;
	int				rank;
	int				j;

	inner = stack;
	rank = 0;
	j = 0;
	while (j < size)
	{
		if (inner->data < outer->data)
			rank++;
		inner = inner->next;
		j++;
	}
	return (rank);
}

void	give_rank(t_linkedlist **stack)
{
	t_linkedlist	*outer;
	int				size;
	int				i;

	if (!stack || !*stack)
		return ;
	size = ft_lstsize(*stack);
	outer = *stack;
	i = 0;
	while (i < size)
	{
		outer->rank = compute_rank(*stack, outer, size);
		outer = outer->next;
		i++;
	}
}
