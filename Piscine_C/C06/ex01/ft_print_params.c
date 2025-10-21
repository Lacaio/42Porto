/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:28:29 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 19:25:58 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	if (argc <= 0)
		return (1);
	while (argv[i])
	{
		j = 0;
		str = argv[i];
		while (str[j])
		{
			write(1, &str[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
