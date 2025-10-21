/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:52:46 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/06 21:32:16 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(int n);

void	writechar(int *c, int n);

void	numgen(int n, int *array, int index, int temp);

void	writechar(int *c, int n)
{
	int		index;
	char	ch;

	index = 0;
	while (index < n)
	{
		ch = c[index] + 48;
		write(1, &ch, 1);
		index++;
	}
	if (c[0] != (10 - n))
		write(1, ", ", 2);
}

void	numgen(int n, int *array, int index, int temp)
{
	if (index == n)
	{
		writechar(array, n);
		return ;
	}
	if (temp > 9)
		return ;
	array[index] = temp;
	numgen(n, array, index + 1, temp + 1);
	numgen(n, array, index, temp + 1);
}

void	ft_print_combn(int n)
{
	int	array[10];

	numgen(n, array, 0, 0);
}

/*int	main(void)
{
	int	n;

	n = 5;
	ft_print_combn(n);
	return (0);
}*/
