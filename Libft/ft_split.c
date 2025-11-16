/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:02:46 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/16 19:48:13 by lprado-l         ###   ########.fr       */
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

static int	fill_arr(char **arr, char const *s, char c)
{
	int	j;
	int	len;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			arr[j] = malloc((len + 1) * sizeof(char));
			if (!arr[j])
			{
				free_all(arr, j - 1);
				return (-1);
			}
			ft_strlcpy(arr[j], s, len + 1);
			j++;
			s += len;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		j;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	j = fill_arr(arr, s, c);
	if (j < 0)
		return (NULL);
	arr[j] = NULL;
	return (arr);
}
