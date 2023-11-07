/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:36 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/08 02:26:28 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_strlen(char *str)
{
	unsigned long long	len;

	len = 0;
	while (*(str + len))
	{
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned long long num, char *base)
{
	unsigned long long		base_len;
	int						len;

	base_len = ft_strlen(base);
	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		len++;
		num = -num;
	}
	if (num < base_len)
	{
		ft_putchar_fd(base[num], 1);
		len++;
	}
	else
	{
		ft_putnbr_base(num / base_len, base);
		ft_putchar_fd(base[num % base_len], 1);
		len++;
	}
	return (len);
}

int	printf_u(unsigned int num, int len)
{
	len += ft_putnbr_base((unsigned long long)num, "0123456789");
	return (len);
}

int	printf_hex(long long num, char c, int len)
{
	unsigned long long	u_num;

	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		len++;
		num *= (-1);
	}
	u_num = (unsigned long long)num;
	if (c == 'x')
	{
		ft_putstr_fd("0x", 1);
		len += (ft_putnbr_base(u_num, "0123456789abcdef") + 2);
	}
	else if (c == 'X')
	{
		ft_putstr_fd("0X", 1);
		len += (ft_putnbr_base(u_num, "0123456789ABCDEF") + 2);
	}
	return (len);
}

int	printf_p(unsigned long long num, int len)
{
	ft_putstr_fd("0x", 1);
	if (num == 0)
		return (printf_c('0', len));
	len += (ft_putnbr_base(num, "0123456789abcdef") + 2);
	return (len);
}
