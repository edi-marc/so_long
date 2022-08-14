/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_end_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:39:42 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 18:06:23 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_windows(t_map *map)
{
	mlx_destroy_window(map->win.mlx, map->win.win);
	final_exit(map);
	return (0);
}

void	final_exit(t_map *map)
{
	free_matrix(map->map);
	exit(0);
}

/*
void	esc(t_map *m)
{
	void	*end;
	int		x;
	t_win	v;

	v = m->win;
	end = mlx_xpm_file_to_image(m->win.mlx, "img/end.xpm", &x, &x);
	mlx_put_image_to_window(v.mlx, v.win, end, 1 * 64, 1 * 64);
	if (m->status == W_GAME)
		print_error("You won! Ora torna a lavorare.\n", 0, m);
	else if (m->status == L_GAME)
		print_error("Game over. Prendi un community service!\n", 0, m);
	else
		return ;
}
*/
