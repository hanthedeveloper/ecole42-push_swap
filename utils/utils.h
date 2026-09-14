/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:23:33 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:35:28 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf/ft_printf.h"

typedef struct s_linkedlist
{
	int					data;
	int					index;
	struct s_linkedlist	*next;
	struct s_linkedlist	*prev;
}	t_linkedlist;

typedef struct s_info
{
	int	strategy;
	int	bench;
	int	findx1;
	int	findx2;
}	t_info;

void	error(void);
void	ft_free_exit(t_linkedlist **a, t_linkedlist **b);
void	free_stack(t_linkedlist **stack);

int		ft_lstsize(t_linkedlist *stack);

int		ft_strcmp(const char *s1, const char *s2);
double	disorder_calculator(t_linkedlist *stack);

void	check_double(t_linkedlist **a);
long	ft_atoi(const char *str, int *i, t_linkedlist **a);

void	check_overlap(int flag_index1, int flag_index2, int *strategy, int *bench);
void	collect_flags(char **argv, int *idx1, int *idx2, int *i);


#endif
