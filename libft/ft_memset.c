/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:42:56 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/11/30 18:43:00 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)str;
	while (n-- > 0)
		*tmp++ = (unsigned char)c;
	return (str);
}
