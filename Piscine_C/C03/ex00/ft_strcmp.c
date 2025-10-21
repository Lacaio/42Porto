/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:50:01 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/14 00:04:29 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
       #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>

       
	int	main(void)
       {
           int res1;
	   int res2;
	   char str1[100] = "asjdh";
	   char str2[100] = "as\tjdh";


               res1 = strcmp(str1, str2);
	       res2 = ft_strcmp(str1, str2);

printf("strcmp: %d\n\nft_strcmp: %d", strcmp(str1, str2), ft_strcmp(str1, str2));

           return (0);
       }
*/
