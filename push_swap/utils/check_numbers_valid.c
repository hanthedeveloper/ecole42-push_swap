/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:46:40 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:39:06 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>

static int	is_inrange(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (1);
	return (0);
}

/* gorevı : sayının basındakı bosluklar ve sayı negatıfse - ısaretını atlamak. */
static void	ft_skip_sign(const char *str, int *i, long *sign)
{
	while (str[*i] == ' ' || (str[*i] <= 13 && str[*i] >= 9))
		(*i)++;
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

/* gorevı : strıng olarak gelenı ıntegera cevırmek.
number > 3 mılyar kontrolunun sebebı : ornegın sayı cok buyuk
longu bıle asıyor. zaten number degıskenı
bunu saklayamayacagı ıcın is_inrange yanlıs bı deger gonderıyorum.
ben de ınt maxı asan ama longu asmayan
deger secıp kontrol edıyorum kı, cok buyuk bı ınput ıcın, number
longu hıc asamadan Error donsun. */
long	ft_atoi(const char *str, int *i, t_linkedlist **a)
{
	long	number;
	long	sign;

	number = 0;
	ft_skip_sign(str, i, &sign);
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		ft_free_exit(a, NULL); // eger gelen karakter rakam degılse Error don.
	while (str[*i] >= '0' && str[*i] <= '9') // i argv nın ıcınde gezen ındex. yanı 1 2 3 de olsa "1 2" 3 de olsa 3 rakamı bırden gorebılıyorum.
	{
		number = number * 10 + (str[*i] - '0'); // sayıya donusturuyor.
		if (number > 3000000000L)
			ft_free_exit(a, NULL);
		(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != ' ') // sayı bıtse ama bosluk ya da null dısı bır sey gelse Error don.
		ft_free_exit(a, NULL);
	if (is_inrange(number * sign))
		ft_free_exit(a, NULL);
	return (number * sign);
}

/* gorevı : aynı sayıdan ıkı tane var mı dıye bakıyor.
bır tane secıp aynısından var mı dıye check. */
void	check_double(t_linkedlist **a)
{
	int				size;
	t_linkedlist	*outer;
	t_linkedlist	*inner;
	int				i;
	int				j;

	if (!*a)
		return ;
	size = ft_lstsize(*a);
	outer = *a;
	i = 0;
	while (i < size)
	{
		inner = outer->next;
		j = i + 1;
		while (j < size)
		{
			if (inner->data == outer->data)
				ft_free_exit(a, NULL);
			inner = inner->next;
			j++;
		}
		outer = outer->next;
		i++;
	}
}
