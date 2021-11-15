/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:46:49 by marsel            #+#    #+#             */
/*   Updated: 2021/11/15 23:34:57 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int	i;
	int	ret;
	va_list ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ret += ft_check_solution(&format[i + 1], ap);
			i+=2;
			continue;
		}
		ret += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}

int	ft_check_solution(const char *fmt, va_list ap)
{
	int		ret;
	char	ch;

	ret = 0;
	if (*fmt == 'c')
	{
		ch = va_arg(ap, int);
		ret = write(1, &ch, 1);
	}
	else if (*fmt == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (*fmt == 'p')
	{
		ret += ft_putstr("0x");
		ret += ft_hexadecimal_p(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	else if (*fmt == 'd' || *fmt == 'i')
		ret += ft_putnbr(va_arg(ap, int));
	else if (*fmt == 'u')
		ret += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (*fmt == 'x')
		ret += ft_hexadecimal(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*fmt == 'X')
		ret += ft_hexadecimal(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*fmt == '%')
		ret = write(1, fmt, 1);
	return (ret);
}
