/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:48:13 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/03/31 21:27:56 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X 1000
# define Y 1000

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_cord
{
	double	x;
	double	y;
	double	z;
	int		col;

}					t_cord;

typedef	struct		s_fdf
{
	int		x_len;
	int		y_len;
	void	*img;
	char	*str;
	void	*mlx;
	void	*win;
	int		max;
	double	sx;
	double	sy;
	double	mas;
	double	pg;
	double	pv;
	double	k;
	t_cord	*lol;
	t_cord	*kek;
}					t_fdf;

typedef struct		s_var
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		q;

}					t_var;

typedef struct		s_split
{
	int		fd;
	int		i;
	int		yy;
	char	*line;
	char	**buf;
}					t_split;

int					ft_split_map(char *str, t_fdf *fdf);
int					ft_color(char *str);
void				ft_rotate(t_fdf *fdf, int i);
void				ft_start_param(t_fdf *fdf);
void				ft_start_draw(t_fdf *fdf);
void				ft_perem(t_fdf *fdf, int i);
void				ft_start_param(t_fdf *fdf);
void				ft_draw_init(t_var *var, t_cord st, t_cord fin);
void				ft_draw_line(t_cord st, t_cord fin, t_fdf *fdf, int i);
void				ft_draw_img(t_fdf *fdf);
int					get_next_line(int fd, char **line);

#endif
