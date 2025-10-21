/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:10:48 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/06 19:46:41 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void);

void	logic_write(int i, int j, int k);

void	logic_write(int i, int j, int k)
{
	i = i + 48;
	j = j + 48;
	k = k + 48;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i != 55)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				logic_write(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
norminette Hello_World.c
cc -Wall -Wextra -Werror Hello_World.c
*/
