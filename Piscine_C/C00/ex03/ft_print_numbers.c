/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:44:53 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/06 21:58:11 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
norminette Hello_World.c
cc -Wall -Wextra -Werror Hello_World.c
*/
