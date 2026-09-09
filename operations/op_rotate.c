/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:27:36 by haincel           #+#    #+#             */
/*   Updated: 2026/09/09 11:27:36 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	rotate(t_linkedlist **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_linkedlist **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_linkedlist **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_linkedlist **a, t_linkedlist **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}