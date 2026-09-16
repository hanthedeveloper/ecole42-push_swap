/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:00:27 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:00:27 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_pairs(t_linkedlist *prev, int j, int size, int *total_pairs)
{
	t_linkedlist	*temp;
	int				mistakes;

	temp = prev->next;
	mistakes = 0;
	while (j < size)
	{
		(*total_pairs)++;
		if ((prev->data) > (temp->data))
			mistakes++;
		temp = temp->next;
		j++;
	}
	return (mistakes);
}

static int	count_mistakes(t_linkedlist *head, int size, int *total_pairs)
{
	t_linkedlist	*prev;
	int				mistakes;
	int				i;

	prev = head;
	mistakes = 0;
	*total_pairs = 0;
	i = 0;
	while (i < size)
	{
		mistakes += count_pairs(prev, i + 1, size, total_pairs);
		prev = prev->next;
		i++;
	}
	return (mistakes);
}

double	disorder_calculator(t_linkedlist *stack)
{
	int	size;
	int	total_pairs;
	int	mistakes;

	if (!stack || stack->next == stack)
		return (0);
	size = ft_lstsize(stack);
	mistakes = count_mistakes(stack, size, &total_pairs);
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}
