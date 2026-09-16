/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:59:59 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 18:19:45 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	error(void)
{
	ft_printf(2, "Error\n");
	exit(1);
}

void	free_stack(t_linkedlist **stack)
{
	t_linkedlist	*current;
	t_linkedlist	*next;
	t_linkedlist	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	(*stack)->prev->next = NULL;
	current = temp;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ft_free_exit(t_linkedlist **a, t_linkedlist **b)
{
	free_stack(a);
	free_stack(b);
	error();
}
