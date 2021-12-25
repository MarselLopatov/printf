/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:00:38 by cdoria            #+#    #+#             */
/*   Updated: 2021/12/25 23:07:15 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_hexadecimal(unsigned long nb, int set)
{
	char	*base;

	if (set)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_print_hexadecimal(nb / 16, set);
		ft_print_hexadecimal(nb % 16, set);
	}
	else
		write (1, &base[nb], 1);
}

int	ft_hexadecimal_p(unsigned long nb)
{
	int				ret;

	ret = 0;
	ft_print_hexadecimal(nb, 1);
	while (nb)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}

int	ft_hexadecimal(unsigned long nb, int x)
{
	int				ret;

	ret = 0;
	if (!nb)
		return (write (1, "0", 1));
	if (x)
		ft_print_hexadecimal(nb, 1);
	else
		ft_print_hexadecimal(nb, 0);
	while (nb)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}
