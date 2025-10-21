/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:26:54 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/14 23:19:31 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	deci_hexa_mixer(char c);

void	deci_hexa_mixer(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] < 32 || str[i] == 127)
			deci_hexa_mixer((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

#include <stdio.h>
int main(void)
{	
	printf("%s - \n", "3\xC6\xD4K\x03+`\xD0\xC1\x9C\x1C\xE1\xCD 7\xCC\xCFo|\
\xAC b\xED\x0B.\xD1\xD1n\xBCo\xBD/\xDDO\xE8\xDE\xA8\xEB\xF2\xFB\x85\xEE\
k\xB 7\xAB\xC7\xDF\xB6\xAE\xB2r\\d5o\xF0\x0E\xA9\xBA\x06\x88?\x81G\x85\xDB\
\xDF\xFA\xA9\xE3\xE3\xB6\xDD\xD0\xFD\xFF\xA9\x9B\x14\x0Bk~\xD1Zg\xE5\x90\
\xC5\x1B\x8A\xA2\xDD\x1Fh\xEA\xAB\xF5\xDC\x1B\xDA\xFF\xE1\x0B8\xBDN\x0fO:\
\x8E\x90\xB9\x0F\xBF\x45\xB6\x9B\xBE\xDD\x97\xD6\xF4\xCB{JI\x9C\xE4|\x1D\
\xB4-\x1B[1;5;31mTROCK YOU42\x08");
	ft_putstr_non_printable("3\xC6\xD4K\x03+`\xD0\xC1\x9C\x1C\xE1\xCD 7\xCC\xCFo|\
\xAC b\xED\x0B.\xD1\xD1n\xBCo\xBD/\xDDO\xE8\xDE\xA8\xEB\xF2\xFB\x85\xEE\
k\xB 7\xAB\xC7\xDF\xB6\xAE\xB2r\\d5o\xF0\x0E\xA9\xBA\x06\x88?\x81G\x85\xDB\
\xDF\xFA\xA9\xE3\xE3\xB6\xDD\xD0\xFD\xFF\xA9\x9B\x14\x0Bk~\xD1Zg\xE5\x90\
\xC5\x1B\x8A\xA2\xDD\x1Fh\xEA\xAB\xF5\xDC\x1B\xDA\xFF\xE1\x0B8\xBDN\x0fO:\
\x8E\x90\xB9\x0F\xBF\x45\xB6\x9B\xBE\xDD\x97\xD6\xF4\xCB{JI\x9C\xE4|\x1D\
\xB4-\x1B[1;5;31mTROCK YOU42\x08");
	return 0;
}
