/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <tprysiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:25:39 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/03/31 21:20:52 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** функція обернення фігури
*/

void	ft_rotate(t_fdf *fdf, int i)
{
	fdf->kek[i].x = fdf->lol[i].x * cos(fdf->pv) - fdf->lol[i].y * sin(fdf->pv);
	fdf->kek[i].y = fdf->lol[i].x * sin(fdf->pv) + fdf->lol[i].y * cos(fdf->pv);
	fdf->kek[i].z = fdf->lol[i].z * fdf->k;
	fdf->kek[i].y = fdf->kek[i].y * cos(fdf->pg) + fdf->kek[i].z * sin(fdf->pg);
}

void	ft_perem(t_fdf *fdf, int i)
{
	fdf->kek[i].x = fdf->kek[i].x * fdf->mas + fdf->sx;
	fdf->kek[i].y = fdf->kek[i].y * fdf->mas + fdf->sy;
}

/*
** зміщення по х і у
*/

void	ft_start_param(t_fdf *fdf)
{
	fdf->max = fdf->x_len * fdf->y_len;
	fdf->sx = X / 2;
	fdf->sy = Y / 2;
	fdf->mas = X / fdf->x_len * 0.75;
	fdf->pg = -0.6155;
	fdf->pv = 0.7854;
	fdf->k = 1;
}

void	ft_start_draw(t_fdf *fdf)
{
	int i;

	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, X, Y, "fdf");
	fdf->kek = (t_cord *)malloc(sizeof(t_cord) * fdf->x_len * fdf->y_len);
	ft_start_param(fdf);
	fdf->img = mlx_new_image(fdf->mlx, X, Y);
	fdf->str = mlx_get_data_addr(fdf->img, &i, &i, &i);
	ft_draw_img(fdf);
}

int		main(int ac, char **ag)
{
	t_fdf fdf;

	if (ac != 2)
		return (write(1, "Right usage: ./fdf <map>\n", 25));
	if (ft_split_map(ag[1], &fdf) == 1)
		exit(write(2, "error map\n", 10));
	ft_start_draw(&fdf);
	return (0);
}
