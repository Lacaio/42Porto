/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:27:34 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/07 22:57:13 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int     main(void)
{
        int     number0;
	int	number1;

	number0 = 5;
	number1 = 8;
	printf("Numbers before ft_swap function call: %d %d", number0, number1);
	ft_swap(&number0, &number1);
	printf("\nNumbers after after ft_ft function call: %d %d", number0, number1);
	return (0);
}
*/
