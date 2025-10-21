/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:04:39 by lprado-l          #+#    #+#             */
/*   Updated: 2025/10/20 09:17:57 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little)
		return (big);
	while (big[i] && i < len)
	{
		if (big[i] == little[i])
		{
			j = i;
			while (big[j] == little[j])
			{
				if (little[j] == '\0' && big[j] == '\0')
					return (big[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
