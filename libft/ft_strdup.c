/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:32:57 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/11/29 12:33:06 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	len = ft_strlen(str);
	tmp = (char*)malloc(sizeof(*str) * (len + 1));
	if (!(tmp))
		return (0);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
