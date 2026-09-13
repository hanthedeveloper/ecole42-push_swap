/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:46:40 by haincel           #+#    #+#             */
/*   Updated: 2026/09/13 00:00:00 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// headerı sıl yenıden yap

#include "utils.h"
#include <limits.h>

static int	is_inrange(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (1);
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

long	ft_atoi(const char *str, int *i, t_linkedlist **a, t_linkedlist **b)
{
	long	number;
	long	sign;

	number = 0;
	ft_skip_sign(str, i, &sign);
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		ft_free_exit(a, b);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		number = number * 10 + (str[*i] - '0');
		if (number > 4000000000L)
			ft_free_exit(a, b);
		(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != ' ')
		ft_free_exit(a, b);
	if (is_inrange(number * sign))
		ft_free_exit(a, b);
	return (number * sign);
}

void	check_double(t_linkedlist **a, t_linkedlist **b)
{
	int				size;
	t_linkedlist	*outer;
	t_linkedlist	*inner;
	int				i;
	int				j;

	if (!*a)
		return ;
	size = ft_lstsize(*a);
	outer = *a;
	i = 0;
	while (i < size)
	{
		inner = outer->next;
		j = i + 1;
		while (j < size)
		{
			if (inner->data == outer->data)
				ft_free_exit(a, b);
			inner = inner->next;
			j++;
		}
		outer = outer->next;
		i++;
	}
}