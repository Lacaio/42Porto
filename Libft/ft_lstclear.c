/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:32:58 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/11 20:34:04 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
  t_list	*tmp;

  if (!lst || !del)
    return (NULL);
  while (*lst)
  {
    tmp = (*lst)->next;
    ft_lstdelone(*lst, del);
    *lst = tmp;
  }
  *lst = NULL;
}
