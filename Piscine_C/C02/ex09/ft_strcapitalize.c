/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:29:20 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/14 20:02:12 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

void	mega_if(char *str, int i);

void	mega_if(char *str, int i)
{
	while (str[i] != '\0')
	{
		if ((!((str[i - 1] > 47 && str[i - 1] < 58)
					|| (str[i - 1] > 64 && str[i - 1] < 91)
					|| (str[i - 1] > 96 && str[i - 1] < 123))
				&& (str[i] > 96 && str[i] < 123)))
		{
			str[i] = str[i] - 32;
		}
		else if ((((str[i - 1] > 47 && str[i - 1] < 58)
					|| (str[i - 1] > 64 && str[i - 1] < 91)
					|| (str[i - 1] > 96 && str[i - 1] < 123))
				&& (str[i] > 64 && str[i] < 91)))
			str[i] = str[i] + 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] > 96 && str[i] < 123)
	{
		str[i] = str[i] - 32;
		i++;
	}
	else
		i++;
	mega_if(str, i);
	return (str);
}
/*
	#include<stdlib.h>
	#include<string.h>
	int main(void){
	char *ch;
	//char ch1[123] = "lsadkfjsls;gjeghehworewoifsafh";
	char ch1[100] = "A=T<9a}P-&^Qu@S':Uz";
        ch = malloc(sizeof(char)*400);
        memcpy(ch, "hi, how are you? 42w#lfifty+and+one", 200 );
	printf("%s", ft_strcapitalize(ch1));
	printf ("\n%d\n", '`');
	return 9;
	}
*/
