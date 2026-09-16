/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baaldirm <baaldirm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:19:19 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 19:28:17 by baaldirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_flag_valid(char *flag, int *flag_index)
{
	char	*flag_arr[7];
	int		i;

	flag_arr[0] = "--adaptive";
	flag_arr[1] = "--simple";
	flag_arr[2] = "--medium";
	flag_arr[3] = "--complex";
	flag_arr[4] = "--bench";
	flag_arr[5] = "--count-only";
	flag_arr[6] = NULL;
	i = 0;
	while (flag_arr[i])
	{
		if (ft_strcmp(flag_arr[i], flag) == 0)
		{
			*flag_index = i;
			return (0);
		}
		i++;
	}
	error();
	return (1);
}

void	collect_flags(char **argv, int *findx1, int *findx2, int *i)
{
	*i = 1;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (*findx1 == -1)
			is_flag_valid(argv[*i], findx1);
		else if (*findx2 == -1)
			is_flag_valid(argv[*i], findx2);
		else
			error();
		(*i)++;
	}
}

void	check_overlap(int findx1, int findx2, int *strategy, int *bench, int *count_only)
{
	*strategy = 0;
	*bench = 0;
	*count_only = 0;
	if (findx1 != -1 && findx2 != -1
		&& (findx1 == findx2 || (findx1 != 4 && findx2 != 4)))
		error();
	if (findx1 == 4)
		*bench = 1;
	if (findx1 == 5)
		*count_only = 1;
	else if (findx1 != -1)
		*strategy = findx1;
	if (findx2 == 4)
		*bench = 1;
	else if (findx2 != -1)
		*strategy = findx2;
}
