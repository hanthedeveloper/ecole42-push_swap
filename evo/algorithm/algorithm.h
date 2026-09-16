/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:51:49 by haincel           #+#    #+#             */
/*   Updated: 2026/09/16 14:55:44 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../utils/utils.h"
# include "../benchmark/benchmark.h"

void	simple(t_linkedlist **a, t_linkedlist **b);
void	medium(t_linkedlist **a, t_linkedlist **b);
void	adaptive(t_linkedlist **a, t_linkedlist **b,
			double disorder, t_bench *pointer);
void	complex(t_linkedlist **a, t_linkedlist **b);

#endif