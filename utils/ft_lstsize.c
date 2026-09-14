/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:00:56 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:00:56 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* daıresel bı lınked lıstın kac node a sahıp oldugunu bulmak. */
int	ft_lstsize(t_linkedlist *stack)
{
	int				size;
	t_linkedlist	*temp;

	if (!stack)
		return (0);
	temp = stack->next;
	size = 1;
	while (temp != stack)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}