/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:09:07 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/13 21:42:57 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write(int n, char *num, int *i)
{
	long int	number;

	number = n;
	if (number < 0)
	{
		number = number * -1;
		num[0] = '-';
		(*i)++;
	}
	if (number > 9)
	{
		ft_write(number / 10, num, i);
	}
	num[*i] = (char)(number % 10) + '0';
	(*i)++;
}

void	count(int n, int *counter)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		(*counter)++;
		num = num * -1;
	}
	if (num > 9)
		count(num / 10, counter);
	(*counter)++;
}

char	*ft_itoa(int n)
{
	char	*num;
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	count(n, &counter);
	num = malloc(counter + 1);
	if (!num)
		return (NULL);
	ft_write(n, num, &i);
	num[i] = '\0';
	return (num);
}
