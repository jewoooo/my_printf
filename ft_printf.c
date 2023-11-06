/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:12:33 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/06 23:04:25 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printf_specifier(va_list *ap, char **format, int n)
{
	if (**format == 'c' || **format == '%')
		n = printf_c(ap, **format,n);
	else if (**format == 's')
		n = printf_s(ap, n);
	else if (**format == 'd' || **format == 'i')
		n = printf_d(ap, n);
	else if (**format == 'u')
		n = printf_u(ap, n);
	else if (**format == 'x' || **format == 'X')
		n = printf_x(ap, n);
	else if (**format == 'p')
		
	return (n);
}

int	ft_printf(const char *format, ...)
{
	int		f_len;
	va_list	ap;

	va_start(ap, format);
	f_len = 0;
	while (*format != '\0')
	{
		if (*format = '%')
		{
			format++;
			f_len = print_specifier(&ap, &format, f_len);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			f_len++;
		}
		format++;
	}
	va_end(ap);
	return (f_len);
}
