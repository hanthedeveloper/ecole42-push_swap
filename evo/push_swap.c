/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:26:06 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 19:27:03 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	call_flag(int flag_index, int bench, t_linkedlist **a,
	t_linkedlist **b, int count_only)
{
	double	disorder;
	t_bench	*temp;

	temp = get_bench_pointer();
	disorder = disorder_calculator(*a);
	temp->strategy = flag_index;
	temp->disorder = disorder;
	if (disorder == 0.00)
	{
		if (flag_index == 0)
			temp->a_strtgy = "O(1)";
		if (bench == 1)
			print_bench();
		return ;
	}
	if (flag_index == 0)
		adaptive(a, b, disorder, temp);
	if (flag_index == 1)
		simple(a, b);
	if (flag_index == 2)
		medium(a, b);
	if (flag_index == 3)
		complex(a, b);
	if (bench == 1)
		print_bench();
	if (count_only == 1)
		print_count();
}

int	main(int argc, char **argv)
{
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	t_info			info;
	int				i;

	stack_a = NULL;
	stack_b = NULL;
	info.findx1 = -1;
	info.findx2 = -1;
	collect_flags(argv, &info.findx1, &info.findx2, &i);
	check_overlap(info.findx1, info.findx2, &info.strategy, &info.bench, &info.count_only);
	if (!argv[i])
		return (0);
	argc--;
	while (argc >= i)
	{
		create_stack_a(argv[argc], &stack_a);
		argc--;
	}
	check_double(&stack_a);
	give_rank(&stack_a);
	call_flag(info.strategy, info.bench, &stack_a, &stack_b, info.count_only);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
