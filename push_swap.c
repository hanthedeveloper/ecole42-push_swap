/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:11:26 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 16:32:20 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	convert_and_check_input(char **argv, t_linkedlist **input_list)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		push((ft_atoi(argv[i])), input_list);
		i++;
	}
	if (check_double(*input_list))
	{
		error();
	}
	return (0);
}

void	call_flag(int flag_index, int bench, t_linkedlist **a, t_linkedlist **b)
{
	selection_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_linkedlist	*head;
	t_linkedlist	*stack_b;
	int				flag_index1;
	int				flag_index2;
	int				strategy;
	int				bench;
	int				i;
	char			**ar;

	head = NULL;
	stack_b = NULL;
	flag_index1 = -1;
	flag_index2 = -1;
	if (argc < 2)
		return (0);
	collect_flags(argv, &flag_index1, &flag_index2, &i);
	resolve_flags(flag_index1, flag_index2, &strategy, &bench);
	if (!argv[i])
		return (0);
	while (i < argc)
	{
		ar = ft_split(argv[i], ' ');
		convert_and_check_input(&ar[0], &head);
		ft_free(ar);
		i++;
	}
	call_flag(strategy, bench, &head, &stack_b);
	return (0);
}