/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:18:09 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/16 21:36:28 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	whitespaces(int i, char *str);

int	sign(int t, int *sign, char *str);

int	number(int i, char *str);

int	whitespaces(int i, char *str)
{
	while (str[i] == 127 || (str[i] >= 0 && str[i] < 33))
		i++;
	return (i);
}

int	sign(int i, int *sign, char *str)
{
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			*sign = *sign * -1;
		i++;
	}
	return (i);
}

int	number(int i, char *str)
{
	int	num;

	num = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	sigh;
	int	num;
	int	i;

	sigh = 1;
	i = 0;
	if (!str[i])
		return (0);
	i = whitespaces(i, str);
	i = sign(i, &sigh, str);
	num = number(i, str);
	return (num * sigh);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char arr[50] = "       \t\t\t\t\t\t\t\t -------++++---23476284laks";

	printf("Atoi: %d\nft_atoi: %d", atoi(arr), ft_atoi(arr));
	return (0);
}
*/
