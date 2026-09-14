/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:52:03 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 16:39:55 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"

/* gorevı : eger buldugumuz sayı asagı yakınsa rra yukarı yakınsa ra cagır. */
static void	sort(t_linkedlist **a, t_linkedlist **b, int size, int min_pos)
{
	if ((size - min_pos) > (min_pos - 0))
	{
		while (min_pos != 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos != size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
}

/* gorevı : daıresel bı lınked lıstte mınımum olan sayıyı on^2 karmasıklıkla buluyor. ve o sayının
oldugu ındexı yanı kacıncı nodeda ıse onu donduruyor. */
static int	find_min(t_linkedlist *temp, int *size)
{
	t_linkedlist	*head;
	int				min_value;
	int				min_pos;
	int				pos;

	head = temp;
	min_value = temp->index;
	min_pos = 0;
	pos = 1;
	temp = temp->next;
	while (temp != head)
	{
		if (temp->index < min_value)
		{
			min_value = temp->index;
			min_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	*size = pos;
	return (min_pos);
}

/* gorevı : mınımum sayıları b ye pushluyor sonra da b den a ya gerı pusluyor a sıralanmıs oluyor. */
void	simple(t_linkedlist **a, t_linkedlist **b)
{
	int	min_pos;
	int	size;

	while (*a && (*a)->next != *a)
	{
		min_pos = find_min(*a, &size);
		sort(a, b, size, min_pos);
	}
	while (*b)
	{
		pa(b, a);
	}
}
