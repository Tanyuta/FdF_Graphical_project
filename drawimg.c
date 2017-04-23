/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:27:21 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/03/31 21:56:58 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** присвоєння клавішам but певних функцій
*/

int		keybut(int but, t_fdf *fdf)
{
	if (but == 53)
		exit(0);
	if (but == 13)
		fdf->pg += 0.0873;
	if (but == 1)
		fdf->pg -= 0.0873;
	if (but == 0)
		fdf->pv += 0.0873;
	if (but == 2)
		fdf->pv -= 0.0873;
	if (but == 87)
		fdf->k += 0.1;
	if (but == 84)
		fdf->k -= 0.1;
	fdf->sx += but == 124 ? 10 : 0;
	fdf->sx -= but == 123 ? 10 : 0;
	fdf->sy -= but == 126 ? 10 : 0;
	fdf->sy += but == 125 ? 10 : 0;
	if (but == 4)
		ft_start_param(fdf);
	fdf->mas *= but == 69 ? 1.3 : 1;
	fdf->mas /= but == 78 ? 1.3 : 1;
	ft_draw_img(fdf);
	return (0);
}

void	ft_draw_init(t_var *var, t_cord st, t_cord fin)
{
	var->dx = fabs(st.x - fin.x);
	var->dy = fabs(st.y - fin.y);
	var->x = fin.x;
	var->y = fin.y;
}

void	ft_draw_line(t_cord st, t_cord fin, t_fdf *fdf, int i)
{
	t_var var;

	ft_draw_init(&var, st, fin);
	if ((var.dx >= var.dy))
	{
		var.q = var.dx;
		var.dy = (st.y - fin.y) / var.dx;
		var.dx = (st.x - fin.x) / var.dx;
		while (var.q-- >= 0)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, var.x, var.y, fdf->lol[i].col);
			(var.x += var.dx) && (var.y += var.dy);
		}
	}
	else
	{
		var.q = var.dy;
		var.dx = (st.x - fin.x) / var.dy;
		var.dy = (st.y - fin.y) / var.dy;
		while (var.q-- >= 0)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, var.x, var.y, fdf->lol[i].col);
			(var.x += var.dx) && (var.y += var.dy);
		}
	}
}

int		game_over(void *str)
{
	str = NULL;
	exit(1);
}

void	ft_draw_img(t_fdf *fdf)
{
	int i;

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	i = -1;
	while (++i < fdf->max)
	{
		ft_rotate(fdf, i);
		ft_perem(fdf, i);
	}
	i = -1;
	while (++i < fdf->max)
	{
		if (i % fdf->x_len != 0)
			ft_draw_line(fdf->kek[i], fdf->kek[i - 1], fdf, i);
		if (i / fdf->x_len > 0)
			ft_draw_line(fdf->kek[i], fdf->kek[i - fdf->x_len], fdf, i);
		mlx_pixel_put(fdf->mlx, fdf->win,\
			fdf->kek[i].x, fdf->kek[i].y, fdf->lol[i].col);
	}
	mlx_hook(fdf->win, 17, 0, game_over, NULL);
	mlx_hook(fdf->win, 2, 0, keybut, fdf);
	mlx_loop(fdf->mlx);
}
