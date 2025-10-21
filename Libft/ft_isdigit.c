/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:27:50 by lprado-l          #+#    #+#             */
/*   Updated: 2025/10/13 19:58:51 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_isdigit(int c)
{
	if(c >= 0 && c <=9)
		return (1);
	return (0);
}
/*
int     main(void)
{
        int c = 9;
        printf("ft: %d", ft_isdigit(c));
        return (0);

}
*/
