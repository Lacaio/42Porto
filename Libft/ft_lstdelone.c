/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:13:50 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/11 20:32:42 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void  ft_lstdelone(t_list *lst, void (*del)(void *))
{
  if (!lst || !del)
    return (NULL);
  del(lst->content);
  free(lst);
}
