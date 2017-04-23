/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:46:13 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/05 20:47:06 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	ag;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		ag = str[i];
		str[i] = str[j];
		str[j] = ag;
		i++;
		j--;
	}
	return (str);
}
