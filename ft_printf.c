/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:46:49 by marsel            #+#    #+#             */
/*   Updated: 2021/11/05 23:00:37 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	va_list ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
//			printf("%c", va_arg(ap, int));
			ft_cehck_solution(&format[i + 1], ap);
			i+=2;
			continue;
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (1);
}

#include <stdio.h>

int main()
{
	printf("1привет %c я Антон\n %s\n", 'A', "а это строка");
	ft_printf("2привет %c я Антон\n %s\n", 'A', "а это строка");
}