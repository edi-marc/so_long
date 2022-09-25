/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:18:37 by edi-marc          #+#    #+#             */
/*   Updated: 2022/09/25 16:22:06 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "errors.h"
# include "libft.h"
# include "../minilibx/mlx.h"

# define VALID_EXT ".ber"

typedef enum e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	ENTER_1 = 36,
	ENTER_2 = 76,
}	t_keys;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_dir;

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
	char	*wall;
	char	*collect;
	char	*play;
}			t_win;

typedef struct s_img
{
	void	*floo;
	void	*exit;
	void	*wall;
	void	*collect;
	void	*play;
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
void	is_closed(t_map *map);
/*	checker_utils.c	*/
void	initial_value(t_map *map);
void	fill_checker(t_map *map, char c);
void	init_win(t_map *map);
void	check_map(t_map *map);
/*	str_utils.c	*/
char	*get_next_line(int fd);
/*	map_loader.c	*/
void	load_map(t_map *map, char *mapf);
/*	map_render.c	*/
void	render_images(t_map *map);
/*	errors.c	*/
void	print_bf_exit_error(char *s, int err);
void	print_exit_error(char *s, int err, t_map *map);
void	free_matrix(char **matrix);
/*	img_map_fill.c	*/
void	fill_windows(t_map *map);
void	set_image_1(t_map *m, int i, int j);
/*	map_key_manager.c	*/
int		command(int keycode, t_map *map);
/*	map_key_helper.c	*/
void	move_helper(t_map *m, int x, int y);
void	print_moves(t_map *map);
/*	map_end_game.c	*/
int		close_windows(t_map *map);
void	final_exit(t_map *map);
void	esc(t_map *m);
void	end_game(t_map *map);
#endif
