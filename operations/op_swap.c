/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:26:53 by haincel           #+#    #+#             */
/*   Updated: 2026/09/08 16:27:22 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BITTI :D

#include "push_swap.h"

/* sa (swap a or b): Swap the first two elements at the top the given stack.
do nothing if there is only one or no elements. */
static void	swap(t_linkedlist *stack)
{
	int	temp;

	if (!stack || !stack->next)
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
	ft_putendl_fd("sa", 1);
}

void	sb(t_linkedlist *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_linkedlist *a, t_linkedlist *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}