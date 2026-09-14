/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:11:26 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 21:44:56 by haincel          ###   ########.fr       */
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

/* gorevı : flag durumuna gore algorıtma cagırmak. */
static void	call_flag(int flag_index, int bench, t_linkedlist **a,
	t_linkedlist **b)
{
	double	disorder;
	t_bench	*temp;

	temp = get_bench_pointer();
	disorder = disorder_calculator(*a);
	temp->strategy = flag_index;
	temp->disorder = disorder;
	if (disorder == 0.00)
	{
		if (bench == 1)
			print_bench();
		return ;
	}
	if (flag_index == 0)
		adaptive(a, b, disorder, temp);
	if (flag_index == 1)
		simple(a, b);
	if (flag_index == 2)
		medium(a, b);
	if (bench == 1)
		print_bench();
}

/* flagları aldıktan sonra argumanlar bıttıyse programı sonlandır. 
edıt 14092026 : bı tane daha struct kurdum flag, strategy ve bench
bılgısını tutuyor. neden? cunku norma gore bı fonskıyon 4 ya da 5
degısken tanımlayabılıyomus ıcınde. ben de structa tasıdım.
poıntersız olmasının sebebı de bellektekı yerı hıc degısmıyor.
sadece bılgı tutuyor. bundan dolayı.
edıt02 : flag_index yerıne findx1/2 oldu satır cok uzuncu kısaltmak
ıcın */
int	main(int argc, char **argv)
{
	t_linkedlist	*stack_a;
	t_linkedlist	*stack_b;
	t_info			info;
	int				i;

	stack_a = NULL;
	stack_b = NULL;
	info.findx1 = -1;
	info.findx2 = -1;
	(void)argc;
	collect_flags(argv, &info.findx1, &info.findx2, &i);
	check_overlap(info.findx1, info.findx2, &info.strategy, &info.bench);
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		create_stack_a(argv[i], &stack_a);
		i++;
	}
	check_double(&stack_a);
	give_rank(&stack_a);
	call_flag(info.strategy, info.bench, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
