/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:33:32 by haincel           #+#    #+#             */
/*   Updated: 2026/09/08 16:25:31 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_linkedlist
{
	int					data;
	struct s_linkedlist	*next;
	struct s_linkedlist	*prev;
}	t_linkedlist;

void	push(int data, t_linkedlist **stack);
int		pop(t_linkedlist **stack);
int		peek(t_linkedlist **stack);
void	swap(t_linkedlist **stack);
void	move(t_linkedlist **from, t_linkedlist **to);
void	ft_putendl_fd(char *s, int fd);

#endif