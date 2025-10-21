/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:11:37 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/08 18:55:49 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	check;
	int	i;
	int	t;

	check = 0;
	while (1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				t = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = t;
				check = 1;
			}
			i++;
		}
		if (check == 1)
			check = 0;
		else
			break ;
	}
}
/*
int 	main(void)
{
	int	n;
	int	tab[18] = {9, 4, 7, 6, 5, 5, 1, 2, 1, 0, 3,7,2,1,7,3,9,2};
	char 	t;
	int	i;

	i = 0;
	n = 18;
	while (i < n)
	{
		t = tab[i] + 48;
		write(1, &t, 1);
		i++;
	}
	ft_sort_int_tab(tab, n);
	write(1, "\n", 1);
	i = 0;
	t = 0;
	while (i < n)
        {
                t = tab[i] + 48;
                write(1, &t, 1);
                i++;
        }
	return (0);
}
*/
