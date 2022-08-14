/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_map_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:21:07 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 10:53:35 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_image_2(t_map *m, int i, int j)
{
	t_img	f;
	t_win	v;

	v = m->win;
	f = m->img;
	if (m->map[i][j] == '0')
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
	else if (m->map[i][j] == 'E')
	{
		mlx_put_image_to_window(v.mlx, v.win, f.exit, j * 64, i * 64);
		m->x_exit = j;
		m->y_exit = i;
	}
	else if (m->map[i][j] == '1')
		mlx_put_image_to_window(v.mlx, v.win, f.wall, j * 64, i * 64);
}

static void	set_image_1(t_map *m, int i, int j)
{
	t_img	f;
	t_win	v;

	v = m->win;
	f = m->img;
	if (m->spl == 8)
		m->spl = 0;
	if (m->map[i][j] == 'F' || m->map[i][j] == 'S')
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
		mlx_put_image_to_window(v.mlx, v.win, m->imgs[m->spl], j * 64, i * 64);
	}
	if (m->map[i][j] == 'P')
	{
		mlx_put_image_to_window(v.mlx, v.win, f.floo, j * 64, i * 64);
		mlx_put_image_to_window(v.mlx, v.win, f.play, j * 64, i * 64);
		m->x = j;
		m->y = i;
	}
	else
		set_image_2(m, i, j);
}

void	fill_windows(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i][j] == '1')
				set_image_1(map, i, j);
		}
	}
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i][j] != '1')
				set_image_1(map, i, j);
		}
	}
}
