/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:17:08 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 11:20:34 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	64 is the tile size (64 x 64)
*/

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	m;

	is_valid(argc, argv, &m)i;
	if (!m.win.mlx)
		print_exit_error(MALLOC_ERR_TXT, MALLOC_ERR, &m);
	m.win.win = mlx_new_window(m.win.mlx, m.col * 64, m.row * 64, "So long");
	init_win(&m);
	fill_windows(&m);
}
