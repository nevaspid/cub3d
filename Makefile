# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oliove <oliove@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 18:39:53 by gloms             #+#    #+#              #
#    Updated: 2024/07/18 00:29:14 by oliove           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d
LIBMLX		:=	./MLX42
HEADERS		:=	-I ./include
MLXA		:= $(LIBMLX)/build/libmlx42.a
HEADERS		:= -I ./include -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/build/libmlx42.a -lm -lglfw #-L 
# ------------------------------ Sources -----------------------------

SRCS		:=	srcs/cub3d.c \
				srcs/minimap/pixelated_assets.c \
				srcs/minimap/print_minimap.c \
				srcs/parsing/read_file.c \
				srcs/parsing/check_filename.c \
				srcs/parsing/parsing_utils.c \
				srcs/parsing/parsing_utils2.c \
				srcs/parsing/check_stored_tab.c \
				srcs/utils/utils.c \
				srcs/utils/utils2.c \
				srcs/utils/split.c \
				srcs/malloc/lst_alloc.c \
				srcs/raycasting/move_player.c \
				srcs/raycasting/init.c \
				srcs/raycasting/calcule.c \
				srcs/raycasting/calcule_dda.c \
				srcs/utils/free_and_exit.c \
				srcs/parsing/flood_fill.c \
				srcs/raycasting/move_player_directions.c \
				srcs/raycasting/draw_primitive.c \
				srcs/raycasting/draw.c \
				srcs/game_loop.c \
				srcs/raycasting/init_text.c \
				srcs/raycasting/direction.c \
				srcs/utils/prim_draw_utils.c \
				srcs/utils/utils_text.c \
# srcs/utils/check_move.c \
# srcs/utils/check_move

SRCS_BONUS		:=	srcs_bonus/cub3d_bonus.c \
				srcs_bonus/minimap_bonus/pixelated_assets_bonus.c \
				srcs_bonus/minimap_bonus/print_minimap_bonus.c \
				srcs_bonus/parsing_bonus/read_file_bonus.c \
				srcs_bonus/parsing_bonus/check_filename_bonus.c \
				srcs_bonus/parsing_bonus/parsing_utils_bonus.c \
				srcs_bonus/parsing_bonus/parsing_utils2_bonus.c \
				srcs_bonus/parsing_bonus/check_stored_tab_bonus.c \
				srcs_bonus/utils_bonus/utils_bonus.c \
				srcs_bonus/utils_bonus/utils2_bonus.c \
				srcs_bonus/utils_bonus/split_bonus.c \
				srcs_bonus/malloc_bonus/lst_alloc_bonus.c \
				srcs_bonus/raycasting_bonus/move_player_bonus.c \
				srcs_bonus/raycasting_bonus/init_bonus.c \
				srcs_bonus/raycasting_bonus/calcule_bonus.c \
				srcs_bonus/raycasting_bonus/calcule_dda_bonus.c \
				srcs_bonus/utils_bonus/free_and_exit_bonus.c \
				srcs_bonus/parsing_bonus/flood_fill_bonus.c \
				srcs_bonus/raycasting_bonus/move_player_directions_bonus.c \
				srcs_bonus/raycasting_bonus/draw_primitive_bonus.c \
				srcs_bonus/raycasting_bonus/draw_bonus.c \
				srcs_bonus/game_loop_bonus.c \
				srcs_bonus/utils_bonus/check_move_bonus.c \
				srcs_bonus/utils_bonus/prim_draw_utils_bonus.c \
				srcs_bonus/utils_bonus/init_bonus.c \
				srcs_bonus/utils_bonus/utils_text.c \
				srcs_bonus/utils_playeur.c \

OBJ_DIR				:=	.objs
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

OBJ_DIR_BONUS		:=	.objs_bonus
OBJS_BONUS		:=	$(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_BONUS:.c=.o))

# ------------------------------ Flags -------------------------------

BREW		:=	$(shell brew --prefix)
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g3 -O3 -march=native -mtune=native -funroll-loops -finline-functions -flto -fomit-frame-pointer -ffast-math -fexpensive-optimizations
RM			:=	rm -rf

$(OBJ_DIR)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) $(HEADERS) $(INC_RL) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) $(HEADERS) $(INC_RL) -c $< -o $@

# ------------------------------ Colors ------------------------------

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Compilation -------------------------
ifeq ($(DEBUG), 1)
	FLAGS += -g3 -fsanitize=address -O3 -march=native -mtune=native -funroll-loops -finline-functions -flto -fomit-frame-pointer -ffast-math -fexpensive-optimizations
endif

ifeq ($(TEST), 1)
	FLAGS = $(filter-out $(OBJS), $(OBJS))
	FLAGS += -g3 -fsanitize=address 
endif

ifeq ($(shell uname -s), Darwin) # if Mac
	CXX := clang++
# Si erreur ici a la compilation commente la ligne ci-dessous
	LIBS += "$(BREW)/Cellar/glfw/3.3.9/lib/"
else
	CXX := g++
endif



all:			$(NAME)

$(MLXA):
	@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME):		$(MLXA) $(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) $(HEADERS) $(OBJS) -o $(NAME) $(LIBS)
				@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

bonus:		$(MLXA) $(OBJS_BONUS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) $(HEADERS) $(OBJS_BONUS) -o $(NAME) $(LIBS)
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
