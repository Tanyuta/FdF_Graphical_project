/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:11:28 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/02 17:11:31 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	char	*str;

	j = 0;
	if (s1 && s2)
	{
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			while (*s1)
				str[j++] = *s1++;
			while (*s2)
				str[j++] = *s2++;
			str[j] = '\0';
			return (str);
		}
	}
	return (0);
}
