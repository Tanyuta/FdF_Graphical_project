/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:46:55 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/01 20:46:57 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if ((tmp = ft_strnew(ft_strlen(s))))
		{
			while (*s)
			{
				tmp[i] = f(i, *s++);
				i++;
			}
		}
		return (tmp);
	}
	return (0);
}
