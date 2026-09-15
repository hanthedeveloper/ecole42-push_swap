/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:00:27 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:00:27 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_mistakes(t_linkedlist *head, int size, int *total_pairs)
{
	t_linkedlist	*prev;
	t_linkedlist	*temp;
	int				mistakes;
	int				i; // dıs dongu
	int				j; // ıc dongu

	prev = head;
	mistakes = 0;
	*total_pairs = 0;
	i = 0;
	while (i < size) // bı node tutup,
	{
		j = i + 1;
		temp = prev->next;
		while (j < size) // tum nodeları gezıcek
		{
			(*total_pairs)++;
			if ((prev->data) > (temp->data)) // o ankı nodun datası oncekınden kucukse,
				mistakes++; // hata vardır.
			temp = temp->next;
			j++;
		}
		prev = prev->next;
		i++; // sonra dıger node ıcın aynısı
	}
	return (mistakes);
}

/* eger lınked lıst bossa ya da bı elemanlıysa dısorder 0.
eger paır yoksa dısorder 0. hataların, toplam ıkılı sayısına bolumu = dısorder */
double	disorder_calculator(t_linkedlist *stack)
{
	int	size;
	int	total_pairs;
	int	mistakes;

	if (!stack || stack->next == stack)
		return (0);
	size = ft_lstsize(stack);
	mistakes = count_mistakes(stack, size, &total_pairs);
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}