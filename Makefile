# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 11:27:35 by edi-marc          #+#    #+#              #
#    Updated: 2022/08/14 13:03:29 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

P1		=	./checker/
P2		=	./errors/
P3		=	./img_utils/
P4		=	./map_utils/
P5		=	./utils/

SRC		=	so_long.c							\
			$(P1)checker_utils.c				\
			$(P1)checker.c						\
			$(P2)errors.c						\
			$(P3)img_util.c						\
			$(P3)img_map_fill.c					\
			$(P4)map_end_game.c					\
			$(P4)map_key_helper.c				\
			$(P4)map_key_manager.c				\
			$(P4)map_loader.c					\
			$(P4)map_render.c					\
			$(P5)util_int.c						\

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	includes

MLX		=	minilibx

RM		=	/bin/rm -f

.c.o:
		$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)

norme:
		@norminette $(SL_SRC)

clean:
			make clean -C minilibx
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mSO_LONG>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

re.all:		fclean

.PHONY:		all clean fclean re
