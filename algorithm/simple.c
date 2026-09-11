/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:41:07 by haincel           #+#    #+#             */
/*   Updated: 2026/09/10 11:50:26 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	sort(t_linkedlist **a, t_linkedlist **b, int index, int min_index)
{
	if ((index - min_index) > (min_index - 0))
	{
		while (min_index != 0)
		{
			ra(a);
			min_index--;
		}
	}
	else
	{
		while (min_index != index)
		{
			rra(a);
			min_index++;
		}
	}
	pb(a, b);
}

static int find_min(t_linkedlist *temp, int *size)
{
	int	head_data;
	int	min_data;
	int	min_index;
	int	index;

	head_data = temp->data;
	min_data = temp->data;
	min_index = 0;
	index = 1;
	temp = temp->next;
	while (temp->data != head_data)
	{
		if (temp->data < min_data)
		{
			min_data = temp->data;
			min_index = index;
		}
		temp = temp->next;
		index++;
	}
	*size = index;
	return (min_index);
}

void	selection_sort(t_linkedlist **a, t_linkedlist **b)
{
	int	min_index;
	int	index;

	while (*a && (*a)->next != *a)
	{
		min_index = find_min(*a, &index);
		sort(a, b, index, min_index);
	}
	while (*b)
		pa(a, b);
}