/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:48:28 by cdoria            #+#    #+#             */
/*   Updated: 2021/12/25 23:05:35 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

int		ft_printf(const char *fmt, ...);
int		ft_check_solution(const char *fmt, va_list ap);
int		ft_hexadecimal(unsigned long nb, int x);
int		ft_hexadecimal_p(unsigned long nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);

#endif