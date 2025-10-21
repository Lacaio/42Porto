/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:55:07 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 19:58:23 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int	n;
	int	i;
	char	*str;

	n = 0;	
	while (src[n])
		n++;
	str = malloc(n*sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
#include <stdio.h>
int	main(void)
{
	char arr[100] = "kjfh sidfoh hsjdfhkkduhfj";
	printf("str: %s",ft_strdup(arr));
	return (0);
}
