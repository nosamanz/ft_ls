/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:29:57 by oozcan            #+#    #+#             */
/*   Updated: 2022/03/05 16:29:58 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_strchecker(va_list arg, int g);
int		ft_uitoa(unsigned int u);
int		print_arry(char *str);
int		ft_bsm_say(unsigned int b);
int		printer_ptr(unsigned long x);
int		print_ptr(unsigned long n);
int		print_hex(unsigned int n, char c);
int		ft_putchar_vol2(char c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif