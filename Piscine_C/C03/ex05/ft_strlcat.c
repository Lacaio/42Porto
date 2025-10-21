/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:06:18 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/14 19:26:15 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;	

	i = 0;
	src_len = 0;
	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len >= size)
		return (src_len + size);
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>


int     main(void)
{
unsigned int n = 100; 
char str1[100] = "1234567899";
char str2[100] = "ajshdgasdahsdg";
char str3[100] = "1234567899";
char str4[100] = "ajshdgasdahsdg";
printf("cat: %zu\nftcat: %d", strlcat(str1, str2, n), ft_strlcat(str3, str4, n));
printf("\n\nstrlcat: %s\nft_strlcat: %s", str1, str3);
return (0);
}
*/
