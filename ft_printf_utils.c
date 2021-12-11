/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:57:53 by rjaanit           #+#    #+#             */
/*   Updated: 2021/12/11 12:02:01 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"ft_printf.h"

int	len_num(long int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n >= 0 && n <= 9)
		return (len);
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putchar(char c)
{
	int		i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putnbr(int nb)
{
	long	x;

	x = nb;
	if (x < 0)
	{
		ft_putchar('-');
		x = x * -1;
	}
	if (x <= 9)
	{
		ft_putchar(x + '0');
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	return (len_num(nb));
}

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{	
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int nb)
{
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (len_num(nb));
}
