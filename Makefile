# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 11:27:35 by edi-marc          #+#    #+#              #
#    Updated: 2022/08/14 13:54:44 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

P1		=	./checker/
P2		=	./errors/
P3		=	./img_utils/
P4		=	./map_utils/

SO_SRCS	=	so_long.c							\
			$(P1)checker_utils.c				\
			$(P1)checker.c						\
			$(P2)errors.c						\
			$(P3)img_map_fill.c					\
			$(P4)map_loader.c					\
			$(P4)map_render.c					\
			$(U_SRCS)							\

U_SRCS	=	$(addprefix utils/, $(SRCS))

SRCS	=	ft_bzero.c ft_calloc.c ft_memset.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strncmp.c ft_strrchr.c str_utils.c

OBJ		=	$(SO_SRC:.c=.o)

INCLUDE	=	includes/

MLX_DIR	=	minilibx/

MLX		=	$(MLX_DIR)mlx.a

RM		=	/bin/rm -f

.c.o:
		$(CC) $(CFLAGS) -I$(INCLUDE) -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) 

norme:
		@norminette $(SL_SRC)

clean:
			make clean -C $(MLX_DIR)
			$(RM) $(OBJS) 

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

re.all:		fclean

.PHONY:		all clean fclean re
