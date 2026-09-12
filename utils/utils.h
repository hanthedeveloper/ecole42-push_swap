/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:23:33 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 16:41:02 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stacklerın kullandıgı linked list yapısı, yazdırma fonskıyonu,
// dısorder hesaplama

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

typedef struct s_linkedlist
{
	int					data;
	int					index;
	struct s_linkedlist	*next;
	struct s_linkedlist	*prev;
}	t_linkedlist;

void	ft_putendl_fd(char *s, int fd);
int	ft_lstsize(t_linkedlist *stack);
int	ft_strcmp(const char *s1, const char *s2);

double	disorder_calculator(t_linkedlist *stack);

int	check_double(t_linkedlist *list);
long	ft_atoi(const char *str);

int	is_flag_valid(char *flag, int *flag_index);
void	resolve_flags(int idx1, int idx2, int *strategy, int *bench);
void	collect_flags(char **argv, int *idx1, int *idx2, int *i);

void	error(void);
char	**ft_split(char const *s, char c);

char	**ft_free(char **res);

#endif
