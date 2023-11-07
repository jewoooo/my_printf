/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:58:04 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/08 02:00:02 by jewoolee         ###   ########.fr       */
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
