/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:48:46 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/02 13:42:37 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

char *ft_strchr(const char *str, int c)
{
	if (c > 127)
		return ((char *)str);
	while (*str != '\0' && *str != c)
		str++;
	if (c == *str)
		return ((char *)str);
	return (0);
}
