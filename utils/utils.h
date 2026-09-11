/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:23:33 by haincel           #+#    #+#             */
/*   Updated: 2026/09/10 16:05:36 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stacklerın kullandıgı linked list yapısı, yazdırma fonskıyonu, dısorder hesaplama

#ifndef UTILS_H
# define UTILS_H

typedef struct s_linkedlist
{
	int					data;
	int					index;
	struct s_linkedlist	*next;
	struct s_linkedlist	*prev;
}	t_linkedlist;

void	ft_putendl_fd(char *s, int fd);
double	disorder_calculator(t_linkedlist *stack);

#endif