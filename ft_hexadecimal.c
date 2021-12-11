/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:17:50 by rjaanit           #+#    #+#             */
/*   Updated: 2021/12/11 14:11:46 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_hexadecimal_low(unsigned int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_hexadecimal_low(nb / 16);
		ft_hexadecimal_low(nb % 16);
	}
	else
		write(1, &base[nb], 1);
	return (ft_len_hexa(nb));
}

int	ft_len_hexa(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

int	ft_hexadecimal_up(unsigned int nb)
{
	int		len;
	char	*base;

	base = "0123456789ABCDEF";
	len = 0;
	if (nb >= 16)
	{
		ft_hexadecimal_up(nb / 16);
		ft_hexadecimal_up(nb % 16);
	}
	else
		ft_putchar(base[nb]);
	return (ft_len_hexa(nb));
}	
