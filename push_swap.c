/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:11:26 by haincel           #+#    #+#             */
/*   Updated: 2026/09/13 00:00:00 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert_and_check_input(char *str, t_linkedlist **a,
		t_linkedlist **b)
{
	int		i;
	long	value;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			value = ft_atoi(str, &i, a, b);
			if (push((int)value, a) == -1)
				ft_free_exit(a, b);
		}
	}
}

static void	call_flag(int flag_index, int bench, t_linkedlist **a, t_linkedlist **b)
{
	selection_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	int				flag_index1;
	int				flag_index2;
	int				strategy;
	int				bench;
	int				i;

	stack_a = NULL;
	stack_b = NULL;
	flag_index1 = -1;
	flag_index2 = -1;
	if (argc < 2)
		return (0);
	collect_flags(argv, &flag_index1, &flag_index2, &i);
	resolve_flags(flag_index1, flag_index2, &strategy, &bench);
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		convert_and_check_input(argv[i], &stack_a, &stack_b);
		i++;
	}
	check_double(&stack_a, &stack_b);
	call_flag(strategy, bench, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}