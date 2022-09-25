/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map:w_key_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:29:40 by edi-marc          #+#    #+#             */
/*   Updated: 2022/09/25 16:57:33 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_down(t_map *m)
{
	if (m->map[m->y + 1][m->x] == '1')
		return ;
	else if (m->map[m->y + 1][m->x] == 'C')
	{
		m->map[m->y + 1][m->x] = '0';
		set_image_1(m, m->y + 1, m->x);
		m->check.collectible--;
	}
	if (m->map[m->y + 1][m->x] == 'E' && !m->check.collectible)
	{
		end_game(m);
		return ;
	}
	else if (m->map[m->y + 1][m->x] == 'E' && m->check.collectible)
		return ;
	move_helper(m, m->x, m->y + 1);
}

static void	move_left(t_map *m)
{
	if (m->map[m->y][m->x - 1] == '1')
		return ;
	else if (m->map[m->y][m->x - 1] == 'C')
	{
		m->map[m->y][m->x - 1] = '0';
		set_image_1(m, m->y, m->x - 1);
		m->check.collectible--;
	}
	if (m->map[m->y][m->x - 1] == 'E' && !m->check.collectible)
	{
		end_game(m);
		return ;
	}
	else if (m->map[m->y][m->x - 1] == 'E' && m->check.collectible)
		return ;
	move_helper(m, m->x - 1, m->y);
}

static void	move_right(t_map *m)
{
	if (m->map[m->y][m->x + 1] == '1')
		return ;
	else if (m->map[m->y][m->x + 1] == 'C')
	{
		m->map[m->y][m->x + 1] = '0';
		set_image_1(m, m->y, m->x + 1);
		m->check.collectible--;
	}
	if (m->map[m->y][m->x + 1] == 'E' && !m->check.collectible)
	{
		end_game(m);
		return ;
	}
	else if (m->map[m->y][m->x + 1] == 'E' && m->check.collectible)
		return ;
	move_helper(m, m->x + 1, m->y);
}

static void	move_up(t_map *m)
{
	if (m->map[m->y - 1][m->x] == '1')
		return ;
	else if (m->map[m->y - 1][m->x] == 'C')
	{
		m->map[m->y - 1][m->x] = '0';
		set_image_1(m, m->y - 1, m->x);
		m->check.collectible--;
	}
	if (m->map[m->y - 1][m->x] == 'E' && !m->check.collectible)
	{
		end_game(m);
		return ;
	}
	else if (m->map[m->y - 1][m->x] == 'E' && m->check.collectible)
		return ;
	move_helper(m, m->x, m->y - 1);
}

int	command(int key, t_map *map)
{
	if (map->status != IN_GAME && key != ESC
		&& key != ENTER_1 && key != ENTER_2)
		return (1);
	if (key == ESC)
		close_windows(map);
	else if (key == W || key == K_UP)
		move_up(map);
	else if (key == S || key == K_DOWN)
		move_down(map);
	else if (key == A || key == K_LEFT)
		move_left(map);
	else if (key == D || key == K_RIGHT)
		move_right(map);
	else if ((key == ENTER_1 || key == ENTER_2) && map->status != IN_GAME)
	//	esc(map);
	return (0);
}
