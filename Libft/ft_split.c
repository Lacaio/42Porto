/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:02:46 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/06 01:30:32 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char const *s, char c, int i)
{
	int	len;
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
		if (s[i] == c && s[i - 1] != c)
			words++;
		i++;
	}
	return (words);
}

void	fail_alloc(char **str)
{
	int	i;

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

	i = 0;
	j = 0;
	k = 0;

	str = (char *) malloc(sizeof(char *) * words);
	if (!str)
		return (NULL);
	if (s[0] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = str_len(s, c, i);
			str[j][k] = s[i];
			k++;
		}
		if (s[i] == c && s[i - 1] != c)
		{
			k = 0;
			j++;
		}
		i++;
		
	}
}
