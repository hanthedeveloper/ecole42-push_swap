/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:10:53 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 11:10:53 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	a;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	a = '\n';
	write(fd, &a, 1);
}

int	ft_lstsize(t_linkedlist *stack)
{
	int				size;
	t_linkedlist	*temp;

	if (!stack)
		return (0); // 
	temp = stack->next;
	size = 1;
	while (temp != stack)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}