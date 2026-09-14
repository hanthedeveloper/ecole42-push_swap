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

/* gorevı : stackı cevırıyor. poınterım artık bı sonrakını gosterdıgı ıcın teknık olarak cevrılmıs oldu. */
static void	rotate(t_linkedlist **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_linkedlist **a)
{
	rotate(a);
	ft_printf(1, "ra\n");
	get_bench_pointer()->op_counter[op_ra]++;
}

void	rb(t_linkedlist **b)
{
	rotate(b);
	ft_printf(1, "rb\n");
	get_bench_pointer()->op_counter[op_rb]++;
}

void	rr(t_linkedlist **a, t_linkedlist **b)
{
	rotate(a);
	rotate(b);
	ft_printf(1, "rr\n");
	get_bench_pointer()->op_counter[op_rr]++;
}