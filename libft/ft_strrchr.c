/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:17:21 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/01 16:17:24 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;
	char *res;

	res = NULL;
	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (res);
}
