/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:07:51 by cdoria            #+#    #+#             */
/*   Updated: 2021/12/25 23:07:06 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	write_nbr(unsigned int nb)
{
	char	ch;

	if (nb < 10)
	{
		ch = nb + '0';
		write(1, &ch, 1);
	}
	else
	{
		write_nbr(nb / 10);
		write_nbr(nb % 10);
	}
}

int	ft_putnbr(int nb)
{
	int				ret;
	unsigned int	nbr;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		ret += write(1, "-", 1);
		nbr = -nb;
	}
	else
		nbr = nb;
	write_nbr(nbr);
	while (nb)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (!nb)
		return (write(1, "0", 1));
	write_nbr(nb);
	while (nb)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}
