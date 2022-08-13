/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:06:54 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 00:15:45 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_images(t_map *map)
{
	int		x;
	int		y;
	t_img	img;

	map->win.floor = "img/floor.xpm";
	map->win.exit = "img/exit.xpm";
	map->win.wall = "img/wall.xpm";
	map->win.play = "img/player.xpm";
	map->win.collect = "img/collect.xpm";
	img.floo = mlx_xpm_file_to_image(map->win.mlx, map->win.floor, &x, &y);
	img.exit = mlx_xpm_file_to_image(map->win.mlx, map->win.exit, &x, &y);
	img.wall = mlx_xpm_file_to_image(map->win.mlx, map->win.wall, &x, &y);
	img.play = mlx_xpm_file_to_image(map->win.mlx, map->win.play, &x, &y);
	img.collect = mlx_xpm_file_to_image(map->win.mlx, map->win.collect, &x, &y);
	map->img = img;
}
