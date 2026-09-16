/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_count_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:53:20 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 19:28:50 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"


static void	sum_op(t_bench *temp)
{
	int	i;
	int	sum;
	int	operations[11];

	operations[0] = op_sa;
	operations[1] = op_sb;
	operations[2] = op_ss;
	operations[3] = op_pa;
	operations[4] = op_pb;
	operations[5] = op_ra;
	operations[6] = op_rb;
	operations[7] = op_rr;
	operations[8] = op_rra;
	operations[9] = op_rrb;
	operations[10] = op_rrr;
	sum = 0;
	i = 0;
	while (i < 11)
	{
		sum = sum + temp->op_counter[operations[i]];
		i++;
	}
	temp->total_op = sum;
}

void	print_count(void)
{
	t_bench	*temp;

	temp = get_bench_pointer();
	sum_op(temp);
	ft_printf(2, "%d\n", temp->total_op);
}
