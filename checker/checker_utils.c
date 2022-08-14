/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:32:05 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 11:23:12 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_map(t_map *map)
{
	int	col;
	int	i;

	i = 0;
	while (map->map[i])
	{
		col = 0;
		while (map->map[i][col])
			col++;
		if (i == 0)
			map->col = col;
		if (map->col != col)
			print_exit_error(NVALID_MAP_TXT, NVALID_MAP, map);
		if ((i != 0 && i != map->row - 1) && map->col != col)
			print_exit_error(NVALID_MAP_TXT, NVALID_MAP, map);
		i++;
	}
	is_closed(map);
	if (!map->check.correct)
		print_exit_error(NVALID_MAP_TXT, NVALID_MAP, map);
}

void	initial_value(t_map *map)
{
	map->check.collectible = 0;
	map->check.correct = true;
	map->check.exit = 0;
	map->check.pos = 0;
	map->check.space = 0;
	map->check.wall = 0;
	map->col = 0;
	map->spl = 0;
	map->n_anim = 0;
	map->status = IN_GAME;
	map->delay = 0;
	map->e_delay = 0;
	map->can_staff_move = true;
}

void	fill_checker(t_map *map, char c)
{
	if (c == 'C')
		map->check.collectible++;
	else if (c == 'E')
		map->check.exit++;
	else if (c == 'P')
		map->check.pos++;
	else if (c == '1')
		map->check.wall++;
	else if (c == '0')
		map->check.space++;
	else if (c != '\n' && c != '\0')
		map->check.correct = false;
}

void	init_win(t_map *map)
{
	render_images(map);
	map->x = 1;
	map->y = 1;
	map->moves = 0;
	map->delay = 0;
}
