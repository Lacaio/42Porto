/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:04:39 by lprado-l          #+#    #+#             */
/*   Updated: 2025/10/21 18:28:57 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len)
	{
		if (big[i] == little[0])
		{
			k = i;
			j = 0;
			while (big[k] == little[j] && k <= len)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
				k++;
			}
		}
		i++;
	}
	return (NULL);
}
