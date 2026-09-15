#include "../operations/operations.h"
#include <stdlib.h>
 
/* gorevı : verılen str ıcınde kac tane sayı (bosluklarla ayrılmıs
token) oldugunu sayar. tmp arrayının boyutunu bulmak ıcın kullanılıyor.
henuz validasyon yapmıyor, onu ft_atoi zaten fill_tmp asamasında yapacak. */
static int	count_numbers(char *str)
{
	int	i;
	int	count;
 
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}
 
/* gorevı : str ıcındekı sayıları SOLDAN SAGA (normal sırayla) ft_atoi
ıle parse edıp tmp arrayına sırasıyla yazıyor. hata varsa ft_atoi
zaten ft_free_exit cagırıp cıkıyor. */
static void	fill_tmp(char *str, long *tmp, t_linkedlist **a)
{
	int	i;
	int	k;
 
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			tmp[k++] = ft_atoi(str, &i, a);
	}
}

/* gorevı : tmp arrayını SONDAN BASA gezıp push() (add_front) ıle
stacke atıyor. boylece bu tek argv'nın ıcındekı sayılar da tersten
pushlanmıs oluyor (genel tersleme mantıgıyla tutarlı olması ıcın). */
static void	push_reverse(long *tmp, int count, t_linkedlist **a)
{
	int	k;
 
	k = count - 1;
	while (k >= 0)
	{
		if (push((int)tmp[k], a) == -1)
			ft_free_exit(a, NULL);
		k--;
	}
}
 
/* gorevı : tek bır argv strıngının ıcındekı sayıları stack a'ya
ekler. once sayıyı sayar (count_numbers), gecıcı arraya normal
sırayla doldurur (fill_tmp), sonra o arrayı tersten pushlar
(push_reverse). boylece bu argv'nın en soldakı sayısı en son
pushlanmıs olur. */
void	create_stack_a(char *str, t_linkedlist **a)
{
	long	*tmp;
	int		count;
 
	count = count_numbers(str);
	if (count == 0)
		return ;
	tmp = (long *)malloc(sizeof(long) * count);
	if (!tmp)
		ft_free_exit(a, NULL);
	fill_tmp(str, tmp, a);
	push_reverse(tmp, count, a);
	free(tmp);
}
