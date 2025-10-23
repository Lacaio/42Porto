/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:07:50 by lprado-l          #+#    #+#             */
/*   Updated: 2025/10/23 12:46:48 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int	i;
	char	*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	i++;
	str = malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}
