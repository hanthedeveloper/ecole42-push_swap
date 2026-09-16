/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:51:44 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 19:26:27 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "../utils/utils.h"

typedef enum e_opc
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr,
}	t_opc;

typedef struct s_bench
{
	double					disorder;
	int						strategy;
	char					*a_strtgy;
	int						total_op;
	int						op_counter[11];
}	t_bench;

t_bench	*get_bench_pointer(void);
void	print_bench(void);
void	print_count(void);


#endif