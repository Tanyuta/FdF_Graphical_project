/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:21:20 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/07 14:21:22 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sort(int *str, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	int				a;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (str[i] < str[j])
			{
				a = str[i];
				str[i] = str[j];
				str[j] = a;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (str);
}
