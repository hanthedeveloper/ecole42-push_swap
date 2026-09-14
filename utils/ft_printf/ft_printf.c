/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:27:51 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 19:57:27 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check(char t, va_list *args, int fd)
{
	if (t == 'c')
		return (ft_putchar_fd((char)va_arg(*args, int), fd));
	if (t == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), fd));
	if (t == 's')
		return (ft_putstr_fd(va_arg(*args, char *), fd));
	if (t == 'f')
		return (ft_putdouble_fd(va_arg(*args, double), fd));
	if (t == '%')
		ft_putchar_fd('%', fd);
	return (0);
}

int	ft_printf(int fd, const char *type, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!type)
		return (-1);
	va_start(args, type);
	i = 0;
	len = 0;
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
		{
			i++;
			len = len + check(type[i], &args, fd);
		}
		else
		{
			write(1, &type[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
