#include "utils.h"

/* daıresel bı lınked lıstın kac node a sahıp oldugunu bulmak. */
int	ft_lstsize(t_linkedlist *stack)
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