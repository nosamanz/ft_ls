/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 02:02:31 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/06 02:51:51 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *a;
	unsigned int b;

	if (!s)
		return (0);
	a = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!a)
		return (0);
	b = 0;
	while (s[b])
	{
		a[b] = f(b, s[b]);
		b++;
	}
	a[b] = '\0';
	return (a);
}
