/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:31:40 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 14:55:33 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "../benchmark/benchmark.h"

void	adaptive(t_linkedlist **a, t_linkedlist **b, double disorder,
	t_bench *pointer)
{
	if (ft_lstsize(*a) == 5)
	{
		pointer->a_strtgy = "O(n^2)";
		simple(a, b);
		return ;
	}
	if (disorder < 0.2)
	{
		pointer->a_strtgy = "O(n^2)";
		simple(a, b);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		pointer->a_strtgy = "O(n√n)";
		medium(a, b);
	}
	else
	{
		pointer->a_strtgy = "O(n log n)";
		complex(a, b);
	}
}
