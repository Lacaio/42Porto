/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:31:59 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/16 21:41:40 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	writechar(char c);

int		base_check(char *base);

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i > 1);
}

void	writechar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		len;
	long	n;

	if (!base_check(base))
		return ;
	i = 0;
	len = 0;
	while (base[len])
		len++;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
	}
	writechar(base[n % len]);
}
/*
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
*/
