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

/* pop the first element at the top of the first given stack called "from",
and push it at the top of the second stack called "to".
do nothing if "from" stack is empty. */
static int	move(t_linkedlist **from, t_linkedlist **to)
{
	int	data;
	int	rank;                    // <-- YENİ satır

	if (!*from)
		return ;
	rank = (*from)->rank;            // <-- YENİ satır (pop'tan ÖNCE, node silinmeden önce)
	data = pop(from);
	if (push(data, to) == -1)
		ft_free_exit(from, to);
	(*to)->rank = rank;               // <-- YENİ satır (push'tan SONRA)
}

/* pa (push a): Take the first element at the top of b and
put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and 
put it at the top of b. Do nothing if a is empty */
void	pa(t_linkedlist **b, t_linkedlist **a)
{
	if (move(b, a))
	{
		ft_printf(1, "pa\n");
		get_bench_pointer()->op_counter[op_pa]++;
	}
}

void	pb(t_linkedlist **a, t_linkedlist **b)
{
	move(a, b);
	ft_printf(1, "pb\n");
	get_bench_pointer()->op_counter[op_pb]++;
}
