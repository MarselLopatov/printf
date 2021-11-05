/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:48:28 by cdoria            #+#    #+#             */
/*   Updated: 2021/11/05 21:24:51 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *, ...);
void	ft_cehck_solution(const char *fmt, va_list ap);


#endif