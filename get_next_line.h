/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:21:58 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/01/18 17:44:36 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_lst
{
	int				fd;
	char			*rest;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_structure
{
	char	buf[BUFF_SIZE + 1];
	int		bts;
	char	*chr;
	char	*ptr;
}					t_vault;

int					get_next_line(const int fd, char **line);

#endif
