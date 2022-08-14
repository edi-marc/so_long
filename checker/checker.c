/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:38:51 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 13:21:02 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((i == 0 || i == map->row - 1)
				&& map->map[i][j] != '1')
				print_exit_error(NO_BORDERS_TXT, NVALID_MAP, map);
			if ((j == 0 || j == map->col - 1) && map->map[i][j] != '1')
				print_exit_error(NO_BORDERS_TXT, NVALID_MAP, map);
			j++;
		}
		i++;
	}
}

static bool	ft_check_map_name(char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename || ft_strlen(dot) != 4
		|| ft_strncmp(dot, VALID_EXT, 4) != 0)
		return (false);
	return (true);
}

void	is_valid(int argc, char **argv, t_map *map)
{
	if (argc < 2)
		print_bf_exit_error(ft_strjoin(ERROR_TXT, ARGS_ERROR_TXT), ARGS_ERROR);
	if (!ft_check_map_name(argv[1]))
		print_bf_exit_error(ft_strjoin(ERROR_TXT, INV_MAP_EXT_TXT), ARGS_ERROR);
	initial_value(map);
	load_map(map, argv[1]);
	if (map->check.collectible < 1 || map->check.pos != 1
		|| map->check.exit < 1)
		print_exit_error(NVALID_MAP_TXT, NVALID_MAP, map);
	check_map(map);
}
