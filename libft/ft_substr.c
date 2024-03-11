/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:32:04 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/06 01:44:11 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t a;
	char *b;
	size_t c;
	size_t sub_len;

	sub_len = 0;
	c = ((size_t)start);
	if (s == 0)
		return (0);
	while (sub_len < len && s[sub_len + start] != '\0')
		sub_len++;
	b = malloc((sub_len + 1) * sizeof(char));
	if (!b)
		return (0);
	a = 0;
	while (a < len && c < ft_strlen(s))
	{
		b[a++] = s[c++];
	}
	b[a] = '\0';
	return (b);
}
