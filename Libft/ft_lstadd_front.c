/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:56:57 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/11 19:05:09 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void  ft_lstadd_front(t_list **lst, t_list *new)
{
  if (!lst || !new)
    return (NULL);
  (*new).next = *lst;
  lst = new;
}
