/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:59:59 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:00:54 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

/* gorevı : stderr a Error yazdırıp programı bıtırmek. */
void	error(void)
{
	ft_printf(2, "Error");
	exit(1);
}

/* gorevı : stack zaten bossa bı sey yapma.
lınked lıst daıresel oldugu ıcın once son elemanın nextını NULL yapıyor. boylece artık daıresel degıl. */
void	free_stack(t_linkedlist **stack)
{
	t_linkedlist	*current;
	t_linkedlist	*next;
	t_linkedlist	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	(*stack)->prev->next = NULL;
	current = temp;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

/* stacklerı freeleyerek  stderr a Error yazıp programı bıtırıyor. */
void	ft_free_exit(t_linkedlist **a, t_linkedlist **b)
{
	free_stack(a);
	free_stack(b);
	error();
}
