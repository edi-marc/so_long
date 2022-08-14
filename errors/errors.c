/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:41:14 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/14 11:23:33 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	print_bf_exit_error(char *s, int err)
{
	perror(s);
	exit(err);
}

void	print_exit_error(char *s, int err, t_map *map)
{
	free_matrix(map->map);
	perror(s);
	exit(err);
}
