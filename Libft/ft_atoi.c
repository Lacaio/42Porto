/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:18:38 by lprado-l          #+#    #+#             */
/*   Updated: 2025/10/20 09:40:43 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr);

int	whitespaces(int i, const char *nptr);

int	sign(int t, int *sign, const char *nptr);

int	number(int i, const char *nptr);

int	whitespaces(int i, const char *nptr)
{
	while (*nptr[i] == 127 || (*nptr[i] >= 0 && *nptr[i] < 33))
		i++;
	return (i);
}

int	sign(int i, int *sign, const char *nptr)
{
		if (*nptr[i] == 45)
			*sign = *sign * -1;
	return (i);
}

int	number(int i, const char *nptr)
{
	int	num;

	num = 0;
	while (*nptr[i] > 47 && *nptr[i] < 58)
	{
		num = num * 10 + (*nptr[i] - 48);
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
	if (!*nptr[i])
		return (0);
	i = whitespaces(i, *nptr);
	i = sign(i, &sigh, *nptr);
	num = number(i, *nptr);
	return (num * sigh);
}
