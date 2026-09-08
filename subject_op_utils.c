/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_op_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:00:03 by haincel           #+#    #+#             */
/*   Updated: 2026/09/08 16:24:08 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa (swap a or b): Swap the first two elements at the top the given stack.
do nothing if there is only one or no elements. */
void	swap(t_linkedlist **stack)
{
	int	temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
}

/* pop the first element at the top of the first given stack called "from",
and push it at the top of the second stack called "to".
do nothing if "from" stack is empty. */
void	move(t_linkedlist **from, t_linkedlist **to)
{
	int	data;

	if (!*from)
		return ;
	data = pop(from);
	push(data, to);
}

void	rotate(t_linkedlist **stack) // ??
{
	
}

void	reverse(t_linkedlist **stack)
{
	
}