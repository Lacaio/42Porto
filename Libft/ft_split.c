/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:02:46 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/13 21:06:54 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*free_all(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	arr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = word_len(s + i, c);
			arr[j] = malloc(sizeof(char) * (len + 1));
			if (!arr[j])
				return (free_all(arr, j - 1));
			ft_strlcpy(arr[j], s + i, len + 1);
			i += len;
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
