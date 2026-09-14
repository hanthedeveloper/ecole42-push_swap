/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:31:40 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 18:20:42 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "../benchmark/benchmark.h"

void	adaptive(t_linkedlist **a, t_linkedlist **b, double disorder, t_bench *pointer)
{
	if (disorder < 0.2)
	{
		pointer->adaptive_strategy = "O(n^2)";
		simple(a, b);
	}
	else if (0.2 <= disorder < 0.5)
	{
		pointer->adaptive_strategy = "O(n√n)";
		medium(a, b);
	}
	else
	{
		pointer->adaptive_strategy = "O(n log n)";
		// complex(a, b);
	}
	// stack sıralı mı flagı her fonksıyon ıcın var
}