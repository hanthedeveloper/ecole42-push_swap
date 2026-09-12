/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:46:40 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 16:41:22 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>

static int	is_inrange(long number)
{
	if (number < INT_MIN || number > INT_MAX)
	{
		return (1);
	}
	return (0);
}

static void	ft_skip_sign(const char *str, int *i, long *sign)
{
	while (str[*i] == ' ' || (str[*i] <= 13 && str[*i] >= 9))
		(*i)++;
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static int	ft_is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
		{
			error();
		}
		i++;
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	long	number;
	long	sign;
	int		i;

	i = 0;
	number = 0;
	ft_skip_sign(str, &i, &sign);
	if (!(ft_is_digit(str)))
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			number = number * 10 + str[i] - '0';
			i++;
		}
	}
	if (!(is_inrange(number * sign)))
		return (number * sign);
	error();
	return (1);
}

int	check_double(t_linkedlist *list)
{
	int				size;
	t_linkedlist	*outer;
	t_linkedlist	*inner;
	int				i;
	int				j;

	if (!list)
		return (0);
	size = ft_lstsize(list);
	outer = list;
	i = 0;
	while (i < size)
	{
		inner = outer->next;
		j = i + 1;
		while (j < size)
		{
			if (inner->data == outer->data)
				return (1);
			inner = inner->next;
			j++;
		}
		outer = outer->next;
		i++;
	}
	return (0);
}