/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:48:35 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/08 18:56:48 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = t;
		i++;
	}
}
/*
int     main(void)
{
	int	number;
	int	array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int 	i = 0;

	number = 10;
	        while(i < number)
        {
                printf("%d, ", array[i]);
                i++;
        }

	ft_rev_int_tab(array, number);
	i = 0;
	
	while(i < number)
	{
		printf("%d, ", array[i]);
		i++;
	}
	return (0);
}
*/
