/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:17:08 by edi-marc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/14 18:17:23 by edi-marc         ###   ########.fr       */
=======
/*   Updated: 2022/08/14 14:57:02 by edi-marc         ###   ########.fr       */
>>>>>>> 47fb8f0db0ec8cec4774362249c6c92ec27d79de
/*                                                                            */
/* ************************************************************************** */

/*
**	64 is the tile size (64 x 64)
*/

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	m;

	is_valid(argc, argv, &m);
	m.win.mlx = mlx_init();
	if (!m.win.mlx)
		print_exit_error(MALLOC_ERR_TXT, MALLOC_ERR, &m);
	m.win.win = mlx_new_window(m.win.mlx, m.col * 64, m.row * 64, "So long");
	init_win(&m);
	fill_windows(&m);
<<<<<<< HEAD
	mlx_hook(m.win.win, 2, 1L << 0, command, &m);
=======

>>>>>>> 47fb8f0db0ec8cec4774362249c6c92ec27d79de
	mlx_loop(m.win.mlx);
}
