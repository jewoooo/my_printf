/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:23:51 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/08 02:18:06 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		printf_c(char c, int len);
int		printf_u(unsigned int num, int len);
int		printf_hex(long long num, char c, int len);
int		printf_p(unsigned long long num, int len);
int		ft_putnbr_base(unsigned long long num, char *base);

#endif