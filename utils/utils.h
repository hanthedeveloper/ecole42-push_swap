/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:23:33 by haincel           #+#    #+#             */
/*   Updated: 2026/09/09 11:35:46 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_linkedlist
{
	int					data;
	struct s_linkedlist	*next;
	struct s_linkedlist	*prev;
}	t_linkedlist;

void	ft_putendl_fd(char *s, int fd);

#endif