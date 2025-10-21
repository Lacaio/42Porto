/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:14:31 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/16 21:44:42 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	writechar(int c);

void	writechar(int c)
{
	c = c + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	number;

	number = nb;
	if (number < 0)
	{
		number = number * -1;
		write(1, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
	}
	writechar(number % 10);
}
/*
int	main(void)
{
	int	nb;
	
	nb = -2147483648;
	ft_putnbr(nb);
	return (0);
}
*/
