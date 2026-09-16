/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:26 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 12:52:26 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	rotate(t_linkedlist **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (1);
	*stack = (*stack)->next;
	return (0);
}

void	ra(t_linkedlist **a)
{
	if (!rotate(a))
	{
		ft_printf(1, "ra\n");
		get_bench_pointer()->op_counter[op_ra]++;
	}
}

void	rb(t_linkedlist **b)
{
	if (!rotate(b))
	{
		ft_printf(1, "rb\n");
		get_bench_pointer()->op_counter[op_rb]++;
	}
}

void	rr(t_linkedlist **a, t_linkedlist **b)
{
	if (!rotate(a) && !rotate(b))
	{
		ft_printf(1, "rr\n");
		get_bench_pointer()->op_counter[op_rr]++;
	}
}
