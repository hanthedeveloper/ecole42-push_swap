/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:53:20 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 19:24:57 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

t_bench	*get_bench_pointer(void)
{
	static t_bench	bench_pointer;

	return (&bench_pointer);
}

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

void	print_bench(void)
{
	t_bench	*temp;

	temp = get_bench_pointer();
	ft_printf(2, "[bench] disorder: %f%%\n", temp->disorder);
	if (temp->strategy == 0)
		ft_printf(2, "[bench] strategy: Adaptive / %s\n", temp->a_strtgy);
	if (temp->strategy == 1)
		ft_printf(2, "[bench] strategy: Simple / O(n^2)\n");
	if (temp->strategy == 2)
		ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	if (temp->strategy == 3)
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	sum_op(temp);
	ft_printf(2, "[bench] total_ops: %d\n", temp->total_op);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d ",
		temp->op_counter[op_sa], temp->op_counter[op_sb],
		temp->op_counter[op_ss],
		temp->op_counter[op_pa]);
	ft_printf(2, "pb: %d ra: %d rb: %d rr: %d ",
		temp->op_counter[op_pb], temp->op_counter[op_ra],
		temp->op_counter[op_rb],
		temp->op_counter[op_rr]);
	ft_printf(2, "rra: %d rrb: %d rrr: %d ",
		temp->op_counter[op_rra], temp->op_counter[op_rrb],
		temp->op_counter[op_rrr]);
}
