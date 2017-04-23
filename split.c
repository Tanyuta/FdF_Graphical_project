/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:57:11 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/03/31 21:09:14 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(char *str)
{
	int i;
	int col;
	int q;

	col = 0;
	if (str == NULL)
		return (16777215);
	if (((i = ft_strlen(str)) < 2) && i > 9)
		return (16777215);
	q = 0;
	while (--i != 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			col += (str[i] - 48) * pow(16, q++);
		else if (str[i] >= 'a' && str[i] <= 'f')
			col += (str[i] - 87) * pow(16, q++);
		else if (str[i] >= 'A' && str[i] <= 'F')
			col += (str[i] - 55) * pow(16, q++);
		else
			return (col);
	}
	return (col);
}

int		ft_super_split(t_fdf *fdf, t_split *s, char *str)
{
	s->i = 0;
	if ((s->fd = open(str, O_RDONLY)) < 3)
		return (1);
	if (get_next_line(s->fd, &s->line) == -1)
		return (1);
	else
	{
		s->buf = ft_strsplit(s->line, ' ');
		while (s->buf[s->i] != NULL)
			s->i++;
		if ((fdf->x_len = s->i) <= 0)
			return (1);
	}
	free(s->line);
	fdf->y_len = 1;
	while (get_next_line(s->fd, &s->line))
	{
		fdf->y_len += 1;
		free(s->line);
	}
	free(s->line);
	close(s->fd);
	return (0);
}

int		ft_mega_super_split(t_fdf *fdf, t_split *s)
{
	while (get_next_line(s->fd, &s->line))
	{
		s->i = 0;
		s->buf = ft_strsplit(s->line, ' ');
		while (s->buf[s->i] && s->i < fdf->x_len)
		{
			fdf->lol[s->yy * fdf->x_len + s->i].x =
			fdf->x_len / 2 - fdf->x_len + s->i + 0.5;
			fdf->lol[s->yy * fdf->x_len + s->i].y =
			fdf->y_len / 2 - fdf->y_len + s->yy + 0.5;
			fdf->lol[s->yy * fdf->x_len + s->i].col =
			ft_color(ft_strchr(s->buf[s->i], 'x'));
			fdf->lol[s->yy * fdf->x_len + s->i].z =
			ft_atoi(s->buf[s->i]);
			free(s->buf[s->i++]);
		}
		if (s->i != fdf->x_len)
			return (1);
		free(s->buf);
		s->yy++;
	}
	return (0);
}

int		ft_split_map(char *str, t_fdf *fdf)
{
	t_split s;

	if (ft_super_split(fdf, &s, str))
		return (1);
	s.fd = open(str, O_RDONLY);
	fdf->lol = (t_cord *)malloc(sizeof(t_cord) * fdf->x_len * fdf->y_len);
	s.yy = 0;
	return (ft_mega_super_split(fdf, &s));
}
