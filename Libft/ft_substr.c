/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/16 18:11:00 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s[l] != '\0')
		l++;
	if (start > l)
	{
		sub_str = malloc(1);
		if (!sub_str)
			return (NULL);
		*sub_str = '\0';
		return (sub_str);
	}
	if (len + start > l)
		len = l - start;
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (s[start] != '\0' && i < len && start <= l)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
