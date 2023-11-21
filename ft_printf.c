/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:12:33 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/21 21:24:16 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(char c, int len)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	len++;
	return (len);
}

int	printf_s(char *s, int len)
{
	if (s == NULL)
	{
		len = printf_s("(null)", len);
		return (len);
	}
	while (*s != '\0')
	{
		len = printf_c(*s, len);
		if (len == (-1))
			return (-1);
		s++;
	}
	return (len);
}

static int	printf_d_i(int num, int len)
{
	char	*s;

	s = ft_itoa(num);
	if (s == NULL)
		return (-1);
	len = printf_s(s, len);
	free(s);
	s = NULL;
	return (len);
}

static int	check_specifier(va_list *ap, char c, int len)
{
	if (c == 'c')
		len = printf_c(va_arg(*ap, int), len);
	else if (c == 's')
		len = printf_s(va_arg(*ap, char *), len);
	else if (c == 'd' || c == 'i')
		len = printf_d_i(va_arg(*ap, int), len);
	else if (c == 'u')
		len = printf_u(va_arg(*ap, unsigned int), len);
	else if (c == 'x' || c == 'X')
		len = printf_hex(va_arg(*ap, unsigned int), c, len);
	else if (c == 'p')
		len = printf_p(va_arg(*ap, void *), len);
	else if (c == '%')
		len = printf_c('%', len);
	else
		len = (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len = check_specifier(&ap, *format, len);
		}
		else
			len = printf_c(*format, len);
		if (len == (-1))
			break ;
		format++;
	}
	va_end(ap);
	return (len);
}
