/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:06:00 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/08 22:07:19 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] > 64 && str[i] < 91)))
			return (0);
		i++;
	}
	return (1);
}
