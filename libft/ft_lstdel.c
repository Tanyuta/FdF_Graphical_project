/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:48:56 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/05 16:48:59 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *nextlist;

	list = *alst;
	while (list)
	{
		nextlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nextlist;
	}
	*alst = NULL;
}
