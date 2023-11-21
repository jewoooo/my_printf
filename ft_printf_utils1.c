/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:36 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/21 21:25:33 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_len(unsigned int n, int radix)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= radix;
		len++;
	}
	return (len);
}

static char	*put_uint(char *s, long long n, char *base, int radix)
{
	int			i;
	long long	div;

	i = 0;
	div = 1;
	while (n / div)
		div *= radix;
	div /= radix;
	while (div != 0)
	{
		s[i] = base[n / div];
		n %= div;
		div /= radix;
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_uitoa_base(unsigned int n, char *base)
{
	char		*s;
	int			radix;
	int			i;
	long long	ll_n;

	radix = 0;
	while (base[radix] != '\0')
		radix++;
	s = (char *)malloc(sizeof(char) * (uint_len(n, radix) + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	ll_n = (long long)n;
	if (n == 0)
	{
		s[i] = base[0];
		s[i + 1] = '\0';
		return (s);
	}
	s = put_uint(s, ll_n, base, radix);
	return (s);
}

int	printf_u(unsigned int num, int len)
{
	char	*s;

	s = ft_uitoa_base(num, "0123456789");
	if (s == NULL)
		return (-1);
	len = printf_s(s, len);
	free(s);
	s = NULL;
	return (len);
}

int	printf_hex(unsigned int num, char c, int len)
{
	char	*s;

	if (c == 'x')
	{
		s = ft_uitoa_base(num, "0123456789abcdef");
		if (s == NULL)
			return (-1);
		len = printf_s(s, len);
	}
	else
	{
		s = ft_uitoa_base(num, "0123456789ABCDEF");
		if (s == NULL)
			return (-1);
		len = printf_s(s, len);
	}
	free(s);
	s = NULL;
	return (len);
}
