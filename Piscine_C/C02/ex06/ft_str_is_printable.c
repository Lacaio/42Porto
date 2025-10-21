/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:07:55 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/08 22:10:01 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] > 31 && str[i] < 127)))
			return (0);
		i++;
	}
	return (1);
}
