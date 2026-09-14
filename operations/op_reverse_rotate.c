/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:17 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 12:52:17 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
/* gorevı : stackı cevırıyor. poınterım artık bı oncekını gosterdıgı
ıcın teknık olarak cevrılmıs oldu. */
static void	reverse_rotate(t_linkedlist **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_linkedlist **a)
{
	reverse_rotate(a);
	ft_printf(1, "rra\n");
	get_bench_pointer()->op_counter[op_rra]++;
}

void	rrb(t_linkedlist **b)
{
	reverse_rotate(b);
	ft_printf(1, "rrb\n");
	get_bench_pointer()->op_counter[op_rrb]++;
}

void	rrr(t_linkedlist **a, t_linkedlist **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf(1, "rrr\n");
	get_bench_pointer()->op_counter[op_rrr]++;
}
