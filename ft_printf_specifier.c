/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:36 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/06 23:02:54 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	printf_c(va_list *ap, char c, int n)
{
	char	arg_c;

	if (c == '%')
	{
		ft_putchar_fd('%', 1);
	}
	else
	{
		arg_c = va_arg(*ap, char);
		ft_putchar_fd(arg_c, 1);
	}
	n++;
	return (n);
}

int	printf_s(va_list *ap, int n)
{
	char	*s;

	s = va_arg(*ap, char *);
	while (*s != '\0')
	{
		ft_putchar_fd(*s, 1);
		n++;
		s++;
	}
	return (n);
}

int	printf_d(va_list *ap, int n)
{
	int		num;
	char	*num_s;

	num = va_arg(*ap, int);
	num_s = ft_itoa(num);
	while (*num_s != '\0')
	{
		ft_putchar_fd(*num_s, 1);
		n++;
		num_s++;
	}
	return (n);
}

int	printf_u(va_list *ap, int n)
{
	unsigned int	num;
	char			*num_s;

	num = va_arg(*ap, unsigned int);
	num_s = ft_uitoa(num);
	while (*num_s != '\0')
	{
		ft_putchar_fd(*num_s, 1);
		n++;
		num_s++;
	}
	return (n);
}
