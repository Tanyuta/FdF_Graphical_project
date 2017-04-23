/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:43:41 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/11/30 19:02:21 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (n--)
	{
		*s1 = *s2++;
		if (*s1 == (unsigned char)c)
			return (s1 + 1);
		s1++;
	}
	return (NULL);
}
