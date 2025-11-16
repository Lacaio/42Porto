/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:33:44 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/16 21:34:19 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_and_terminate(char *dst, char const *s1,
	char const *s2, size_t total_len)
{
	size_t	i;
	size_t	len1;

	len1 = ft_strlen(s1);
	i = 0;
	while (i < len1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < total_len)
	{
		dst[i] = s2[i - len1];
		i++;
	}
	dst[total_len] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_copy_and_terminate(str, s1, s2, len1 + len2);
	return (str);
}
