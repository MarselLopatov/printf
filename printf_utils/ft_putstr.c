/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:03:47 by cdoria            #+#    #+#             */
/*   Updated: 2021/12/25 23:05:21 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	ret;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = ft_strlen(str);
	write (1, str, ret);
	return (ret);
}
