/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:27:37 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/06 00:53:18 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t sizedst;
	size_t sizesrc;

	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	j = ft_strlen(dst);
	if (dstsize <= sizedst)
		return (dstsize + sizesrc);
	i = 0;
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (sizedst + sizesrc);
}
