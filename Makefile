# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 11:27:35 by edi-marc          #+#    #+#              #
#    Updated: 2022/08/14 17:56:39 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

D1		=	./checker/
D2		=	./errors/
D3		=	./img_utils/
D4		=	./map_utils/
D5		=	./utils/

SO_SRCS	=	so_long.c							\
			$(D1)checker_utils.c				\
			$(D1)checker.c						\
			$(D2)errors.c						\
			$(D3)img_map_fill.c					\
			$(D4)map_loader.c					\
			$(D4)map_render.c					\
			$(D4)map_key_manager.c				\
			$(D4)map_key_helper.c				\
			$(D4)map_end_game.c					\
			$(U_SRCS)							\

U_SRCS	=	$(addprefix $(D5), $(SRCS))

SRCS	=	ft_bzero.c ft_calloc.c ft_memset.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strncmp.c ft_strrchr.c str_utils.c

OBJS	=	$(SO_SRCS:.c=.o)

INCLUDE	=	includes

MLX_DIR	=	minilibx

MLX		=	mlx

RM		=	/bin/rm -f

MLX_FLAGS	=	-framework OpenGL -framework AppKit

.c.o:
		$(CC) $(CFLAGS) -I$(INCLUDE) -I$(MLX_DIR) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX) $(MLX_FLAGS) $(OBJS) -o $(NAME)  

clean:
			make clean -C $(MLX_DIR)
			$(RM) $(OBJS) 

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

.PHONY:		all clean fclean re
