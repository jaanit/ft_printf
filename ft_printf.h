/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:17:47 by rjaanit           #+#    #+#             */
/*   Updated: 2021/12/11 12:59:57 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

int		ft_type(va_list arg, const char c);
int		ft_printf(const char *str, ...);
int		len_num(long int n);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_putnbr_u(unsigned int nb);
int		ft_hexadecimal_low(unsigned int nb);
int		ft_hexadecimal_up(unsigned int nb);
int		ft_len_hexa(unsigned int nb);
void	ft_hexadecimal_ptr(unsigned long long nb);
int		ft_len_ptr(unsigned long long nb);
int		ft_p(unsigned long long ptr);
int		ft_imprime_pourcentage(void);

#endif
