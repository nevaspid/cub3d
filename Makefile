# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oliove <oliove@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 18:39:53 by gloms             #+#    #+#              #
#    Updated: 2024/05/30 00:25:41 by oliove           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d
LIBMLX		:=	./MLX42/build/libmlx42.a
# ------------------------------ Sources -----------------------------

SRCS		:=	cub3d.c \
				minimap/pixelated_assets.c \
				minimap/print_minimap.c \
				parsing/read_file.c \
				parsing/check_filename.c \
				parsing/parsing_utils.c \
				parsing/parsing_utils2.c \
				parsing/check_stored_tab.c \
				utils/utils.c \
				utils/utils2.c \
				utils/split.c \
				malloc/lst_alloc.c \
				raycasting/move_player.c \
				raycasting/init.c \
				raycasting/calcule.c \
				utils/free_and_exit.c \
				parsing/flood_fill.c \
				debug/debug.c \
				raycasting/move_player_directions.c \

OBJ_DIR		:=	.objs
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ------------------------------ Flags -------------------------------

BREW		:=	$(shell brew --prefix)
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g3 -fsanitize=address
RM			:=	rm -rf

$(OBJ_DIR)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) $(INC_RL) -c $< -o $@

# ------------------------------ Colors ------------------------------

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Compilation -------------------------

all:			$(NAME)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) MLX42/build/libmlx42.a -I include -lglfw -lm -L "$(BREW)/Cellar/glfw/3.3.9/lib/"
				@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"



# -------------------------------- Rules -----------------------------

clean:

				@ $(RM) $(OBJ_DIR)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean

				@ $(RM) $(NAME) $(RM)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all bonus clean fclean re
