/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:57:41 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 18:11:51 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_helper(t_map *m, int x, int y)
{
	t_img	f;
	int		tx;
	int		ty;

	tx = m->x * 64;
	ty = m->y * 64;
	f = m->img;
	mlx_put_image_to_window(m->win.mlx, m->win.win, f.floo, tx, ty);
	m->map[m->y][m->x] = '0';
	m->y = y;
	m->x = x;
	tx = m->x * 64;
	ty = m->y * 64;
	mlx_put_image_to_window(m->win.mlx, m->win.win, f.play, tx, ty);
	m->moves++;
	//print_moves(m);
}
