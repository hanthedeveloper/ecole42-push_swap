/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:37:55 by haincel           #+#    #+#             */
/*   Updated: 2026/09/08 15:56:45 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BU ZATEN BITMISTI :D

#include "push_swap.h"
#include <stdlib.h>

/* push: stack data structer mantıgı dolayısıyla,
cagırıldıgında verılen data ıle yenı node olusturarak
verılen lınked lıstın sureklı basına ekleme yapar*/
void	push(int data, t_linkedlist **stack)
{

	t_linkedlist	*newnode;

	if (!stack)
		return ;
	newnode = (t_linkedlist *)malloc(sizeof(t_linkedlist));
	if (!newnode)
		return ;
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = *stack;
	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/* lınked lıstın tepesındekı datanın stackten cıkarılması ıcındır.
boylece yenı data bı alttakı olur.
or: stack bası -> 1 2 3 4 poptan sonra stack bası -> 2 3 4 */
int	pop(t_linkedlist **stack)
{
	int				popdata;
	t_linkedlist	*temp;

	if (!stack || !*stack)
		return (0);
	popdata = (*stack)->data;
	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
	return (popdata);
}

/* stack yapısındakı en tepedekı datayı dondurur */
int	peek(t_linkedlist **stack)
{
	if (!stack || !*stack)
		return (0);
	return ((*stack)->data);
}