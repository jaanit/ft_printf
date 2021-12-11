/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:47:54 by rjaanit           #+#    #+#             */
/*   Updated: 2021/12/11 14:14:16 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<unistd.h>

int	ft_type(va_list arg, const char c)
{
	int		len_printf;

	len_printf = 0;
	if (c == 'c')
		len_printf += ft_putchar((va_arg(arg, int)));
	else if (c == 's')
		len_printf += ft_putstr((va_arg(arg, char *)));
	else if (c == 'i' || c == 'd')
		len_printf += ft_putnbr((va_arg(arg, int)));
	else if (c == 'u')
		len_printf += ft_putnbr_u((va_arg(arg, int)));
	else if (c == 'x')
		len_printf += ft_hexadecimal_low((va_arg(arg, unsigned int)));
	else if (c == 'X')
		len_printf += ft_hexadecimal_up((va_arg(arg, unsigned int)));
	else if (c == 'p')
		len_printf += ft_p((va_arg(arg, unsigned long long)));
	else if (c == '%')
		len_printf += ft_imprime_pourcentage();
	return (len_printf);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len_printf;
	int		i;

	i = 0;
	len_printf = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			else
				len_printf += ft_type(arg, str[i + 1]);
			i++;
		}
		else
			len_printf += ft_putchar(str[i]);
		i++;
	}	
	va_end(arg);
	return (len_printf);
}
