/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:00:38 by cdoria            #+#    #+#             */
/*   Updated: 2021/11/15 23:56:13 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long	ft_pow(int a, int b)
{
	unsigned long	ret;

	ret = 1;
	while (b)
	{
		ret *= a;
		b--;
	}
	return (ret);
}

int	ft_hexadecimal(unsigned long nb, char *base)
{
	unsigned long	ret;
	unsigned long	temp;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	temp = nb;
	while (temp)
	{
		ret++;
		temp /= 16;
	}
	temp = ft_pow(16, ret);
	while (temp > 1)
	{
		temp /= 16;
		write (1, &base[nb / temp], 1);
		nb %= temp;
	}
	return (ret);
}

int	ft_hexadecimal_p(unsigned long	nb, char *base)
{
	unsigned long	ret;
	unsigned long	temp;
	char			*result;

	if (!nb)
		return (write(1, "0", 1));
	temp = nb;
	ret = 0;
	while (temp)
	{
		ret++;
		temp /= 16;
	}
	result = (char *) malloc(ret * sizeof(char));
	if (!result)
		return (0);
	temp = 0;
	while (nb != 0)
	{
		result[temp++] = base[nb % 16];
		nb /= 16;
	}
	while (temp--)
		write(1, &result[temp], 1);
	free (result);
	return (ret);
}
