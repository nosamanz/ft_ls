/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:12:19 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/05 23:24:37 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "./headers/libft.h"

void *ft_memmove(void *dest, const void *src, size_t len)
{
	char *ptr_dest;
	char *ptr_src;

	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (ptr_src < ptr_dest)
	{
		while (len-- > 0)
		{
			ptr_dest[len] = ptr_src[len];
		}
	}
	else if (ptr_src > ptr_dest)
	{
		ft_memcpy(dest, src, len);
	}
	return (dest);
}
