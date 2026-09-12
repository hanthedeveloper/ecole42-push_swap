/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:14:39 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 11:14:39 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_mistakes(t_linkedlist *head, int size, int *total_pairs)
{
	t_linkedlist	*prev;
	t_linkedlist	*temp;
	int				mistakes;
	int				i; // dıs dongu
	int				j; // ıc dongu

	prev = head;
	mistakes = 0;
	*total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		temp = prev->next;
		while (j < size)
		{
			(*total_pairs)++;
			if (prev->index > temp->index)
				mistakes++;
			temp = temp->next;
			j++;
		}
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