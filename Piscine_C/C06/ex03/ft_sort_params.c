/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:51:10 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/18 16:23:28 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *str1, char *str2);

void	logic(int argc, char **argv);

void	writechar(int argc, char **argv);

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	logic(int argc, char **argv)
{
	int		check;
	int		i;
	char	*temp;

	check = 0;
	while (1)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
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

void	writechar(int argc, char **argv)
{
	int	k;
	int	l;

	k = 1;
	while (k < argc)
	{
		l = 0;
		while (argv[k][l])
		{
			write(1, &argv[k][l], 1);
			l++;
		}
		k++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	logic(argc, argv);
	writechar(argc, argv);
	return (0);
}
