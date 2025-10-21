/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:57:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/07 23:03:25 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int a;
	int b;
	int divResult;
	int modResult;
	
	a = 9;
	b = 2;
	divResult = 0;
	modResult = 0;
//	printf("Numbers before ft_div_mod: %d %d", divResult, modResult);
	ft_div_mod(a, b, &divResult, &modResult);
//	printf("\nNumbers after ft_div_mod: %d %d", divResult, modResult);
	return (0);
}
*/
