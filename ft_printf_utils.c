/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:58:04 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/06 23:04:54 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_int_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*put_u_int(char *ptr, long long num)
{
	int			i;
	long long	div;

	i = 0;
	div = 1;
	while (num / div)
		div *= 10;
	div /= 10;
	while (div != 0)
	{
		ptr[i++] = (num / div) + '0';
		num %= div;
		div /= 10;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_itoa(unsigned int n)
{
	char			*n_str;
	int				i;
	long long		num;

	n_str = (char *)malloc(sizeof(char) * (u_int_len(n) + 1));
	if (n_str == NULL)
		return (NULL);
	i = 0;
	num = (long long)n;
	if (num == 0)
	{
		n_str[i] = '0';
		n_str[i + 1] = '\0';
		return (n_str);
	}
	n_str = put_u_int(n_str, num);
	return (n_str);
}
