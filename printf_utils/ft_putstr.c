/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:03:47 by cdoria            #+#    #+#             */
/*   Updated: 2021/11/15 23:28:12 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

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
