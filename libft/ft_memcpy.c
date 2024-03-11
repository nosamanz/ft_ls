/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:49:42 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/14 13:49:51 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *ptr_dest;
	unsigned char *ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
