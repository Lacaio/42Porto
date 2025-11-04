/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:23:18 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/04 12:40:34 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
int	i;
int	j;
int	k;
int	len_s1;
int	len_set;
char	*str;

i = 0;
j = 0;
len_set = 0;
len_s1 = 0;
while (set[len_set] != '\0')
	len_set++;
while (s1[len_s1] != '\0')
	len_s1++;
while (s1[i] == set[j] && s1[i] != '\0')
{
	j++;
	if (set[j] == '\0')
		j = 0;
	i++;

}
while (
}
