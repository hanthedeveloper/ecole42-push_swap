/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:38 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 17:03:14 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/* sa (swap a or b): Swap the first two elements at the top the given stack.
do nothing if there is only one or no elements. */
static void	swap(t_linkedlist *stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
}

/* sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.
swaplar sadece degerlerı degıstırdıgı node u ve head poınterına dokunmadıkları ıcın
cıft poıntera ıhtıyac yok. */
void	sa(t_linkedlist *a)
{
	swap(a);
	ft_printf(1, "sa\n");
	get_bench_pointer()->op_counter[op_sa]++;
}

void	sb(t_linkedlist *b)
{
	swap(b);
	ft_printf(1, "sb\n");
	get_bench_pointer()->op_counter[op_sb]++;
}

void	ss(t_linkedlist *a, t_linkedlist *b)
{
	swap(a);
	swap(b);
	ft_printf(1, "ss\n");
	get_bench_pointer()->op_counter[op_ss]++;
}