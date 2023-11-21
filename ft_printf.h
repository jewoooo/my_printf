/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewoolee <jewoolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:23:51 by jewoolee          #+#    #+#             */
/*   Updated: 2023/11/21 21:27:45 by jewoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		printf_c(char c, int len);
int		printf_s(char *s, int len);
int		printf_u(unsigned int num, int len);
int		printf_hex(unsigned int num, char c, int len);
int		printf_p(void *ptr, int len);

char	*ft_itoa(int n);

#endif