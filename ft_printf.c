/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:46:49 by marsel            #+#    #+#             */
/*   Updated: 2021/12/25 23:05:37 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ret += ft_check_solution(&format[i + 1], ap);
			i += 2;
			continue ;
		}
		ret += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}

int	ft_check_solution(const char *fmt, va_list ap)
{
	char	ch;

	if (*fmt == 'c')
	{
		ch = va_arg(ap, int);
		return (write(1, &ch, 1));
	}
	else if (*fmt == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (*fmt == 'p')
		return (ft_putstr("0x") + ft_hexadecimal_p(va_arg(ap, unsigned long)));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (*fmt == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	else if (*fmt == 'x')
		return (ft_hexadecimal(va_arg(ap, unsigned int), 1));
	else if (*fmt == 'X')
		return (ft_hexadecimal(va_arg(ap, unsigned int), 0));
	else if (*fmt == '%')
		return (write(1, fmt, 1));
	return (0);
}
