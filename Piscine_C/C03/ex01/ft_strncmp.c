/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:25:03 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/14 00:03:46 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]) && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
       #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>

       
	int	main(void)
{
int n = 1;
char str1[100] = "at";
char str2[100] = "asjdhsdflf";

           return (0);
       }
*/
