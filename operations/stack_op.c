/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:37:55 by haincel           #+#    #+#             */
/*   Updated: 2026/09/09 11:29:00 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include <stdlib.h>

/* push: stack data structer mantıgı dolayısıyla,
cagırıldıgında verılen data ıle yenı node olusturarak
verılen lınked lıstın sureklı basına ekleme yapar.
edit01: lısteyı cembersel yaptım headın prevı lıstenın sonu oluyor yanı */
void	push(int data, t_linkedlist **stack)
{
	t_linkedlist	*newnode;
	t_linkedlist	*tail;

	if (!stack)
		return ;
	newnode = (t_linkedlist *)malloc(sizeof(t_linkedlist));
	if (!newnode)
		return ;
	newnode->data = data;
	if (!*stack)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		*stack = newnode;
		return ;
	}
	tail = (*stack)->prev;
	newnode->next = *stack;
	newnode->prev = tail;
	tail->next = newnode;
	(*stack)->prev = newnode;
	*stack = newnode;
}

/* lınked lıstın tepesındekı datanın stackten cıkarılması ıcındır.
boylece yenı data bı alttakı olur.
or: stack bası -> 1 2 3 4 poptan sonra stack bası -> 2 3 4 
edit01: bu da lıste cembersel oldugu ıcın edıtlendı */
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

/* stack yapısındakı en tepedekı datayı dondurur */
int	peek(t_linkedlist **stack)
{
	if (!stack || !*stack)
		return (0); // burda da
	return ((*stack)->data);
}