/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:45:28 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 21:23:44 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* bu fonskıyon bı stacktekı en kucuk sayıya  */
void	give_rank(t_linkedlist **stack)
{
	t_linkedlist	*outer;
	t_linkedlist	*inner;
	int				rank;
	int				size;
	int				i;
	int				j;

	if (!stack || !*stack)
		return ;
	size = ft_lstsize(*stack);
	outer = *stack;
	i = 0;
	while (i < size)
	{
		rank = 0;
		inner = *stack;
		j = 0;
		while (j < size)
		{
			if (inner->data < outer->data)
				rank++;
			inner = inner->next;
			j++;
		}
		outer->rank = rank;
		outer = outer->next;
		i++;
	}
}