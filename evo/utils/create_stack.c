/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 19:24:03 by haincel           #+#    #+#             */
/*   Updated: 2026/09/15 19:24:05 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"
#include <stdlib.h>

static int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

static void	fill_tmp(char *str, long *tmp, t_linkedlist **a)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			tmp[k++] = ft_atoi(str, &i, a);
	}
}

static void	push_reverse(long *tmp, int count, t_linkedlist **a)
{
	int	k;

	k = count - 1;
	while (k >= 0)
	{
		if (push((int)tmp[k], a) == -1)
			ft_free_exit(a, NULL);
		k--;
	}
}

void	create_stack_a(char *str, t_linkedlist **a)
{
	long	*tmp;
	int		count;

	count = count_numbers(str);
	if (count == 0)
		return ;
	tmp = (long *)malloc(sizeof(long) * count);
	if (!tmp)
		ft_free_exit(a, NULL);
	fill_tmp(str, tmp, a);
	push_reverse(tmp, count, a);
	free(tmp);
}
