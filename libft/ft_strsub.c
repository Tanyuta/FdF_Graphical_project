/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:46:02 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/02 15:46:07 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		{
			while (len--)
			{
				str[i++] = s[start++];
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (0);
}
