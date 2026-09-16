/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:03 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 18:14:17 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"

static void	sort(t_linkedlist **a, t_linkedlist **b, int size, int min_pos)
{
	if ((size - min_pos) > (min_pos - 0))
	{
		while (min_pos != 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos != size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
}

static int	find_min(t_linkedlist *temp, int *size)
{
	t_linkedlist	*head;
	int				min_value;
	int				min_pos;
	int				pos;

	head = temp;
	min_value = temp->data;
	min_pos = 0;
	pos = 1;
	temp = temp->next;
	while (temp != head)
	{
		if (temp->data < min_value)
		{
			min_value = temp->data;
			min_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	*size = pos;
	return (min_pos);
}

void	simple(t_linkedlist **a, t_linkedlist **b)
{
	int	min_pos;
	int	size;

	while (*a && (*a)->next != *a)
	{
		min_pos = find_min(*a, &size);
		sort(a, b, size, min_pos);
	}
	while (*b)
	{
		pa(b, a);
	}
}
