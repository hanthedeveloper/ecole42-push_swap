/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:38 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 18:16:51 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	swap(t_linkedlist *stack)
{
	int	temp;

	if (!stack || stack->next == stack)
		return (1);
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	return (0);
}

void	sa(t_linkedlist *a)
{
	if (!swap(a))
	{
		ft_printf(1, "sa\n");
		get_bench_pointer()->op_counter[op_sa]++;
	}
}

void	sb(t_linkedlist *b)
{
	if (!swap(b))
	{
		ft_printf(1, "sb\n");
		get_bench_pointer()->op_counter[op_sb]++;
	}
}

void	ss(t_linkedlist *a, t_linkedlist *b)
{
	if (!swap(a) && !swap(b))
	{
		ft_printf(1, "ss\n");
		get_bench_pointer()->op_counter[op_ss]++;
	}
}
