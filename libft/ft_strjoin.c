/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:57:16 by oozcan            #+#    #+#             */
/*   Updated: 2022/02/14 13:57:25 by oozcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *string;
	int i;
	int end_s1;

	if (!s1 || !s2)
		return (NULL);
	string = malloc(((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	end_s1 = i;
	i = 0;
	while (s2[i] != '\0')
	{
		string[end_s1 + i] = s2[i];
		i++;
	}
	string[end_s1 + i] = '\0';
	return (string);
}
