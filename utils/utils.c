#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	a;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	a = '\n';
	write(fd, &a, 1);
}