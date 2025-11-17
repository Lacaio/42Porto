/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:18:38 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/17 22:07:17 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespaces(int i, const char *nptr)
{
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r' ))
		i++;
	return (i);
}

static int	sign(int i, int *sign, const char *nptr)
{
	if (nptr[i] == '-')
	{
		*sign = *sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (i);
}

static int	number(int i, const char *nptr)
{
	int	num;

	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	sigh;
	int	num;
	int	i;

	sigh = 1;
	i = 0;
	if (!nptr[i])
		return (0);
	i = whitespaces(i, nptr);
	i = sign(i, &sigh, nptr);
	num = number(i, nptr);
	return (num * sigh);
}
