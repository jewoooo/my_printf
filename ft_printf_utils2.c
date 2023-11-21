/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:22:38 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/21 21:22:49 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long long n, char *base, int *ptr)
{
	unsigned long long		radix;

	if ((*ptr) == (-1))
		return ;
	radix = 0;
	while (base[radix] != '\0')
		radix ++;
	if (n < radix)
	{
		*ptr = printf_c(base[n], *ptr);
		if (*ptr == (-1))
			return ;
	}
	else
	{
		ft_putnbr_base(n / radix, base, ptr);
		*ptr = printf_c(base[n % radix], *ptr);
		if (*ptr == (-1))
			return ;
	}
}

int	printf_p(void *ptr, int len)
{
	unsigned long long	ulld_n;
	long long			lld_n;

	if (ptr < 0)
	{
		len = printf_c('-', len);
		if (len == (-1))
			return (-1);
		lld_n = (long long)ptr;
		ulld_n = (unsigned long long)lld_n * (-1);
	}
	else
		ulld_n = (unsigned long long)ptr;
	len = printf_s("0x", len);
	if (len == (-1))
		return (-1);
	ft_putnbr_base(ulld_n, "0123456789abcdef", &len);
	return (len);
}
