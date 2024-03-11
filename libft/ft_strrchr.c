/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:14:36 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/05 23:37:56 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *last_pos;

	last_pos = 0;
	if (c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			last_pos = (char *)s;
		s++;
	}
	if (last_pos)
		return (last_pos);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
