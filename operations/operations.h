/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:19:12 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 11:23:21 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "../utils/utils.h"

void	push(int data, t_linkedlist **stack);
int		pop(t_linkedlist **stack);
int		peek(t_linkedlist **stack);

void	sa(t_linkedlist *a);
void	sb(t_linkedlist *b);
void	ss(t_linkedlist *a, t_linkedlist *b);

void	pa(t_linkedlist **b, t_linkedlist **a);
void	pb(t_linkedlist **a, t_linkedlist **b);

void	ra(t_linkedlist **a);
void	rb(t_linkedlist **b);
void	rr(t_linkedlist **a, t_linkedlist **b);

void	rra(t_linkedlist **a);
void	rrb(t_linkedlist **b);
void	rrr(t_linkedlist **a, t_linkedlist **b);

#endif