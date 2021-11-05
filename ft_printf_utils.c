#include "printf.h"
#include "libft/libft.h"


#include <stdio.h> 		// DELETE
void	ft_cehck_solution(const char *fmt, va_list ap)
{
	char ch;


	if (*fmt == 'c')
	{
		ch = va_arg(ap, int);
		write(1, &ch, 1);
	}
	else if (*fmt == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
}
