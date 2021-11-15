/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:07:51 by cdoria            #+#    #+#             */
/*   Updated: 2021/11/15 23:56:41 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int				ret;
	unsigned int	temp;
	char			*result;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	temp = nb;
	while (nb)
	{
		ret++;
		nb /= 10;
	}
	result = (char *) malloc(ret * sizeof(char));
	if (!result)
		return (0);
	nb = 0;
	while (temp != 0)
	{
		result[nb++] = temp % 10 + '0';
		temp /= 10;
	}
	while (nb--)
		write(1, &result[nb], 1);
	free (result);
	return (ret);
}

int	ft_putnbr(int nb)
{
	int				ret;
	unsigned int	temp;
	char			*result;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		ret += write(1, "-", 1);
		nb = -nb;
	}
	temp = nb;
	while (nb)
	{
		ret++;
		nb /= 10;
	}
	result = (char *) malloc(ret * sizeof(char));
	if (!result)
		return (0);
	nb = 0;
	while (temp != 0)
	{
		result[nb++] = temp % 10 + '0';
		temp /= 10;
	}
	while (nb--)
		write(1, &result[nb], 1);
	free (result);
	return (ret);
}