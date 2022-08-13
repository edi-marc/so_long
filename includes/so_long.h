/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:18:37 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/13 17:07:13 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

# define VALID_EXT ".ber"

typedef struct s_check_map
{
	int		space;
	int		wall;
	int		collectible;
	int		exit;
	int		pos;
	bool	correct;
}			t_check_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	char	*floor;
	char	*exit;
	char	*exit2;
	char	*wall;
	char	*coin;
	char	*play1;
	char	*play2;
	char	*play3;
	char	*play4;
}			t_win;

typedef struct s_img
{
	void	*enem;
	void	*spaw;
	void	*floo;
	void	*exit;
	void	*exit2;
	void	*wall;
	void	*coin;
	void	*play1;
	void	*play2;
	void	*play3;
	void	*play4;
}			t_img;

typedef enum e_game
{
	IN_GAME,
	W_GAME,
	L_GAME,
}	t_game;

typedef struct s_map
{
	t_check_map	check;
	t_win		win;
	t_img		img;
	t_game		status;
	void		**imgs;
	int			row;
	int			col;
	int			x;
	int			y;
	char		**map;
	int			moves;
	int			x_exit;
	int			y_exit;
	int			delay;
	int			delay2;
	int			e_delay;
	int			n_anim;
	int			spl;
	bool		can_staff_move;
}			t_map;

/*	checker.c	*/
void	is_valid(int argc, char **argv, t_map *map);
/*	checker_utils.c	*/
void	initial_value(t_map *map);
void	fill_checker(t_map *map, char c);
/*	str_utils.c	*/
char	*get_next_line(int fd);
/*	map_loader.c	*/
void	load_map(t_map *map, char *mapf);
/*	errors.c	*/
void	print_bf_exit_error(char *s, int err);
void	print_exit_error(char *s, int err, t_map *map);
#endif
