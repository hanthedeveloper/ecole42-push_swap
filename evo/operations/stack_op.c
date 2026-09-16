/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:51 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 18:15:53 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include <stdlib.h>

int	push(int data, t_linkedlist **stack)
{
	t_linkedlist	*newnode;
	t_linkedlist	*tail;

	if (!stack)
		return (0);
	newnode = (t_linkedlist *)malloc(sizeof(t_linkedlist));
	if (!newnode)
		return (-1);
	newnode->data = data;
	if (!*stack)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		*stack = newnode;
		return (0);
	}
	tail = (*stack)->prev;
	newnode->next = *stack;
	newnode->prev = tail;
	tail->next = newnode;
	(*stack)->prev = newnode;
	*stack = newnode;
	return (0);
}

int	pop(t_linkedlist **stack)
{
	int				popdata;
	t_linkedlist	*temp;
	t_linkedlist	*tail;

	if (!stack || !*stack)
		return (0);
	popdata = (*stack)->data;
	temp = *stack;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		free(temp);
		return (popdata);
	}
	tail = (*stack)->prev;
	*stack = temp->next;
	(*stack)->prev = tail;
	tail->next = *stack;
	free(temp);
	return (popdata);
}
