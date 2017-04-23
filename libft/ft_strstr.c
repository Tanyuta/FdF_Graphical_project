/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:35:28 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/11/29 12:35:33 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int i;
	int j;

	i = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (find[j] != '\0' && str[i + j] == find[j])
			j++;
		if (find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
