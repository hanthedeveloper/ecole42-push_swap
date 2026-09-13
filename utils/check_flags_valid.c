/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:19:19 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 16:41:27 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_flag_valid(char *flag, int *flag_index)
{
	char	*flag_arr[6];
	int		i;

	flag_arr[0] = "--adaptive";
	flag_arr[1] = "--simple";
	flag_arr[2] = "--medium";
	flag_arr[3] = "--complex";
	flag_arr[4] = "--bench";
	flag_arr[5] = NULL;
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

void	collect_flags(char **argv, int *idx1, int *idx2, int *i)
{
	*i = 1;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (*idx1 == -1)
			is_flag_valid(argv[*i], idx1);
		else if (*idx2 == -1)
			is_flag_valid(argv[*i], idx2);
		else
			error();
		(*i)++;
	}
}

void	resolve_flags(int idx1, int idx2, int *strategy, int *bench)
{
	*strategy = 0;
	*bench = 0;
	if (idx1 != -1 && idx2 != -1
		&& (idx1 == idx2 || (idx1 != 4 && idx2 != 4)))
		error();
	if (idx1 == 4)
		*bench = 1;
	else if (idx1 != -1)
		*strategy = idx1;
	if (idx2 == 4)
		*bench = 1;
	else if (idx2 != -1)
		*strategy = idx2;
}