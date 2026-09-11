#include "operations.h"
/* daıresel bı lınked lıstte kac node var onu donduruyor */
static int	ft_lstsize(t_linkedlist *stack)
{
	int				size;
	t_linkedlist	*temp;

	if (!stack)
		return (0);
	temp = stack->next;
	size = 1;
	while (temp != stack)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
/*kaç tane chunk olabileceğini hesaplar*/
static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}
/*stack b en büyük sayının yerini bulur.*/
static int	find_max_pos(t_linkedlist *stack)
{
	t_linkedlist	*head;
	int				max;
	int				max_pos;
	int				pos;

	head = stack;
	max = stack->index;
	max_pos = 0;
	pos = 0;
	do
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	while (stack != head);
	return (max_pos);
}
/*stack b'den en büyükten başlayarak sırayla a ya pushlar.*/
static void	push_max_to_a(t_linkedlist **a, t_linkedlist **b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_pos(*b);
	size = ft_lstsize(*b);

	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rb(b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < size)
		{
			rrb(b);
			max_pos++;
		}
	}
	pa(a, b);
}
/*
** chunk_sort - Kayan pencere (chunk) mantığıyla yığını sıralar.
** 1. Aşama: A'daki elemanları [i, i + chunk_size] aralığına göre filtreler;
**    küçükleri B'nin üstüne, ortadakileri B'nin dibine (rb) atarak kum saati yapısı kurar.
** 2. Aşama: B'deki en büyük elemanları minimum rotasyonla tepeye getirip A'ya geri dizer.
*/
void	chunk_sort(t_linkedlist **a, t_linkedlist **b)
{
	int	chunk_size;
	int	i;
	int	size;

	size = stack_size(*a);
	chunk_size = ft_sqrt(size);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
		push_max_to_a(a, b);
}