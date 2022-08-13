/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:06:54 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/13 18:34:42 by edi-marc         ###   ########.fr       */
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
	map->win.exit2 = "img/exit2.xpm";
	map->win.wall = "img/wall.xpm";
	map->win.play1 = "img/player/player1.xpm";
	map->win.play2 = "img/player/player2.xpm";
	map->win.play3 = "img/player/player3.xpm";
	map->win.play4 = "img/player/player4.xpm";
	map->win.coin = "img/animation/coins0.xpm";
	render_staff(map);
	img.floo = mlx_xpm_file_to_image(map->win.mlx, map->win.floor, &x, &y);
	img.exit = mlx_xpm_file_to_image(map->win.mlx, map->win.exit, &x, &y);
	img.exit2 = mlx_xpm_file_to_image(map->win.mlx, map->win.exit2, &x, &y);
	img.wall = mlx_xpm_file_to_image(map->win.mlx, map->win.wall, &x, &y);
	img.play1 = mlx_xpm_file_to_image(map->win.mlx, map->win.play1, &x, &y);
	img.play2 = mlx_xpm_file_to_image(map->win.mlx, map->win.play2, &x, &y);
	img.play3 = mlx_xpm_file_to_image(map->win.mlx, map->win.play3, &x, &y);
	img.play4 = mlx_xpm_file_to_image(map->win.mlx, map->win.play4, &x, &y);
	img.coin = mlx_xpm_file_to_image(map->win.mlx, map->win.coin, &x, &y);
	map->img = img;
}