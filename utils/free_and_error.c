#include "utils.h"

/* gorevı : stderr a Error yazdırıp programı bıtırmek. */
void	error(void)
{
	ft_putendl_fd("Error", 2);
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
