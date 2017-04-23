/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:35:10 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/09 18:28:44 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (n > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	while (n > 0)
	{
		dst[i] = '\0';
		i++;
		n--;
	}
	return (dst);
}
