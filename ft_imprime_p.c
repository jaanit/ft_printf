/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imprime_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:09:05 by rjaanit           #+#    #+#             */
/*   Updated: 2021/12/11 14:02:20 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_len_ptr(unsigned long long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_hexadecimal_ptr(unsigned long long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_hexadecimal_ptr(nb / 16);
		ft_hexadecimal_ptr(nb % 16);
	}
	else
		write(1, &base[nb], 1);
}

int	ft_p(unsigned long long ptr)
{
	int		len;

	len = 0;
	len += write(1, "0x", 2);
	ft_hexadecimal_ptr(ptr);
	len += ft_len_ptr(ptr);
	return (len);
}

int	ft_imprime_pourcentage(void)
{
	write(1, "%", 1);
	return (1);
}
