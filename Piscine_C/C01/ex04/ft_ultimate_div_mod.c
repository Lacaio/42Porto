/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:29:13 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/07 23:06:05 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}
/*
int     main(void)
{
        int a;
        int b;

        a = 70;
        b = 34;
        printf("Numbers before ft_ultimate_div_mod function call: %d %d", a, b);
        ft_ultimate_div_mod(&a, &b);
        printf("\nNumbers after ft_ultimate_div_mod function call: %d %d", a, b);
        return (0);
}
*/
