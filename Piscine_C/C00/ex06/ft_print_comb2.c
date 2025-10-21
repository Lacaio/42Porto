/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:31:08 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/06 19:48:34 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	writechar(int c);

void	writechar(int c)
{
	c = c + 48;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	number0;
	int	number1;

	number0 = 0;
	number1 = 0;
	while (number0 < 99)
	{
		number1 = number0 + 1;
		while (number1 < 100)
		{
			writechar(number0 / 10);
			writechar(number0 % 10);
			write(1, " ", 1);
			writechar(number1 / 10);
			writechar(number1 % 10);
			if (number0 != 98 || number1 != 99)
				write(1, ", ", 2);
			number1++;
		}
		number0++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
