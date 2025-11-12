/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:02:46 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/06 19:56:44 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

int	str_count(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if(s[0] == c)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == '\0' && s[i] != c))
			words++;
		i++;
	}
	return (words);
}

void	fail_alloc(char **str)
{
	int	i;

	i = 0;
	while (!str[i])
		free(str[i++]);
	free(str);
	
}
char **ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	len;
	char **str;
	int	check;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	check = 1;
	str = NULL;
	str = (char **) malloc(sizeof(char *) * (str_count(s, c) + 1));
	if (!str)
		return (NULL);
	str[str_count(s, c) - 1] = (char *)NULL;
	if (s[0] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (check)
			{
				len = str_len(s, c, i);
				str[j] = (char *) malloc((sizeof(char *) * len) + 1);
				if (!str[j])
				{
					fail_alloc(str);
					return (NULL);
				}
				check = 0;
			}
			str[j][k] = s[i];
			k++;
		}
		if (s[i] == c && s[i - 1] != c)
		{
			str[j][k] = '\0';
			check = 1;
			k = 0;
			j++;
		}
		i++;
	}
	return (str);
}
