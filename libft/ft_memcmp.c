/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:01:39 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/18 13:01:42 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "./headers/libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n)
	{
		if (*ptr != *ptr2)
			return (*ptr - *ptr2);
		ptr++;
		ptr2++;
		n--;
	}
	return (0);
}
