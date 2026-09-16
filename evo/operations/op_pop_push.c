/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pop_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:12 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 12:52:12 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	move(t_linkedlist **from, t_linkedlist **to)
{
	int	data;
	int	rank;

	if (!*from)
		return (1);
	rank = (*from)->rank;
	data = pop(from);
	if (push(data, to) == -1)
		ft_free_exit(from, to);
	(*to)->rank = rank;
	return (0);
}

void	pa(t_linkedlist **b, t_linkedlist **a)
{
	if (!move(b, a))
	{
		ft_printf(1, "pa\n");
		get_bench_pointer()->op_counter[op_pa]++;
	}
}

void	pb(t_linkedlist **a, t_linkedlist **b)
{
	if (!move(a, b))
	{
		ft_printf(1, "pb\n");
		get_bench_pointer()->op_counter[op_pb]++;
	}
}
