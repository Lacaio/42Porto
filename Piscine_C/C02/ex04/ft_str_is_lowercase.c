/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:28:04 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/08 22:05:20 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] > 96 && str[i] < 123)))
			return (0);
		i++;
	}
	return (1);
}
