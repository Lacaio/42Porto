/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 03:55:14 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/16 21:40:52 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	writechar(int c, int fd)
{
	c = c + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	number;

	number = n;
	if (number < 0)
	{
		number = number * -1;
		write(fd, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	writechar(number % 10, fd);
}
