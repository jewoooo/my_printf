/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:36 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/08 22:46:12 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	printf_strlen(char *str)
{
	unsigned long long	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putnbr_base(long long num, char *base, int *ptr)
{
	unsigned long long		big_num;
	unsigned long long		base_len;

	big_num = (unsigned long long)num;
	if (big_num < 0)
	{
		ft_putchar_fd('-', 1);
		(*ptr)++;
		big_num *= (-1);
	}
	base_len = printf_strlen(base);
	if (big_num < base_len)
	{
		(*ptr)++;
		ft_putchar_fd(base[big_num], 1);
	}
	else
	{
		ft_putnbr_base(big_num / base_len, base, ptr);
		(*ptr)++;
		ft_putchar_fd(base[big_num % base_len], 1);
	}
}

int	printf_u(unsigned int num, int len)
{
	ft_putnbr_base((long long)num, "0123456789", &len);
	return (len);
}

int	printf_hex(unsigned int num, char c, int len)
{
	long long	ll_num;

	ll_num = (long long)num;
	if (c == 'x')
		ft_putnbr_base(ll_num, "0123456789abcdef", &len);
	else if (c == 'X')
		ft_putnbr_base(ll_num, "0123456789ABCDEF", &len);
	return (len);
}

int	printf_p(long long num, int len)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(num, "0123456789abcdef", &len);
	len += 2;
	return (len);
}
