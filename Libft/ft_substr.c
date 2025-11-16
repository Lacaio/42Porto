/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:15:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/16 20:06:31 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;
	size_t	actual_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub_str = (char *)malloc(1);
		if (!sub_str)
			return (NULL);
		*sub_str = '\0';
		return (sub_str);
	}
	actual_len = len;
	if (len > s_len - start)
		actual_len = s_len - start;
	sub_str = (char *)malloc(actual_len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, actual_len + 1);
	return (sub_str);
}
