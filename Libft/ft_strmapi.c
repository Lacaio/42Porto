/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:38:52 by lprado-l          #+#    #+#             */
/*   Updated: 2025/11/09 21:12:42 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  int i;
  int len;
  char  *str;

  if (!s || !f)
    return (NULL);
  len = 0;
  while (s[len] != '\0')
    len++;
  str = malloc(len + 1);
  if (!str)
    return (NULL);
  i = 0;
  while (i < len)
  {
    str[i] = f(i, s[i]);
    i++;
  }
  str[i] = '\0';
  return (str);
}
