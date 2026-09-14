/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:27:38 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 19:53:28 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr_fd(int number, int fd)
{
	int	len;

	len = 0;
	if (number == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (number < 0)
	{
		len += ft_putchar_fd('-', fd);
		number = -number;
	}
	if (number >= 10)
		len += ft_putnbr_fd(number / 10, fd);
	len += ft_putchar_fd((number % 10) + '0', fd);
	return (len);
}

/* double yazdırmıyor da sayıyı once 10000 carparak ınteger a donusturuyor.
sonra sayının ılk kısmını putnbr ıle yazdırıp araya 
"." koyup ıkıncı kısmını yazdırıyor.*/
int	ft_putdouble_fd(double number, int fd)
{
	int	len;
	int	temp;
	int	i;

	i = 0;
	len = 0;
	temp = number * 10000;
	len += ft_putnbr_fd((temp / 100), fd);
	ft_putchar_fd('.', fd);
	len++;
	len += ft_putnbr_fd((temp % 100), fd);
	return (len);
}
