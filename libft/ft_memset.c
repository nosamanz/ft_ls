/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:50:38 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/14 13:50:42 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

void *ft_memset(void *dest, int byt, size_t len)
{
	size_t i;
	unsigned char *str;

	i = 0;
	str = (unsigned char *)dest;
	while (i < len)
	{
		str[i] = byt;
		i++;
	}
	return (dest);
}
