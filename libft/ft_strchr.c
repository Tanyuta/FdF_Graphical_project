/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:17:13 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/01 16:17:15 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}
