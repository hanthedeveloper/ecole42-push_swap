/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:23:33 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 11:16:51 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stacklerın kullandıgı linked list yapısı, yazdırma fonskıyonu,
// dısorder hesaplama

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
int	ft_lstsize(t_linkedlist *stack);

#endif