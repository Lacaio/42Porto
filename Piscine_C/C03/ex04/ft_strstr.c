/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:31:45 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/13 23:53:55 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

int		logic(int i, int len, char*str, char *to_find);

int	logic(int i, int len, char *str, char *to_find)
{
	int	j;
	int	k;

	if (str[i] == to_find[0])
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k])
		{
			if (k == len)
				return (j);
			j++;
			k++;
		}
	}
	return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	i;
	int	ret;

	len = 0;
	i = 0;
	if (!to_find[len])
		return (str);
	while (to_find[len] != '\0')
		len++;
	len--;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			ret = logic(i, len, str, to_find);
			if (ret != -1)
			{
				return (&str[ret - len]);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
char str1[100] = "";
char str2[100] = "";

printf("strstr: %s\n\nft_strstr: %s", strstr(str1, str2), ft_strstr(str1, str2));

return (0);
}
*/
