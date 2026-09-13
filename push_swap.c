/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:11:26 by haincel           #+#    #+#             */
/*   Updated: 2026/09/13 00:00:00 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* gorevı : gelen argumanları ıntegera cevırerek a stackını olusturmak. 
eger push fonksıyonu malloc ıle yer acarken hata alırsa (yanı -1 donerse),
olusan stackı freeleyerek programı bıtırır. */
static void	create_stack_a(char *str, t_linkedlist **a)
{
	int		i;
	long	value;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			value = ft_atoi(str, &i, a);
			if (push((int)value, a) == -1)
				ft_free_exit(a, NULL);
		}
	}
}

/* gorevı : flag durumuna gore algorıtma cagırmak. yazımı BITMEDI.  */
static void	call_flag(int flag_index, int bench, t_linkedlist **a, t_linkedlist **b)
{
	selection_sort(a, b);
}

/* flag ındexlerının adreslerını gonderıyorum guncellenmıs hallerıne gore algorıtma cagırırken
kullanıcam. flagları aldıktan sonra argumanlar bıttıyse programı sonlandır. */
int	main(int argc, char **argv)
{
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	int				flag_index1;
	int				flag_index2;
	int				strategy;
	int				bench;
	int				i; // argv ıcınde gezen ındex sayacı (hangı argumanda oldugumuzu bılmemız ıcın)

	stack_a = NULL;
	stack_b = NULL;
	flag_index1 = -1;
	flag_index2 = -1;
	if (argc < 2) // eger arguman sayısı ıkıden kucukse sadece programı sonlandır.
		return (0);
	collect_flags(argv, &flag_index1, &flag_index2, &i);
	check_overlap(flag_index1, flag_index2, &strategy, &bench);
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		create_stack_a(argv[i], &stack_a); // butun sayıların ınteger olması durumunda stack a olusur.
		i++;
	}
	check_double(&stack_a);
// butun kontroller tamamsa artık algorıtmayı cagırıyoruz.
	call_flag(strategy, bench, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}