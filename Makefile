# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 18:18:42 by nagaudey          #+#    #+#              #
#    Updated: 2025/02/26 12:05:39 by nagaudey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -fPIC
LDFLAGS = -fPIE
libft = ./libft
minilibx = ./minilibx-linux
mlx = $(minilibx)/libmlx_Linux.a
CC = cc

# Source files with their full paths
SRC = ft_map.c libft/get_next_line/get_next_line.c libft/ft_split.c libft/ft_strchr2.c ft_render.c \
		end.c ft_set.c main.c ft_move.c ft_close.c ft_cutmap.c ft_check_path.c ft_clone_map.c \
		ft_put.c print_bonus.c ft_set_end.c ft_set_enemy.c

# Create object files paths while preserving directory structure
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
DEPS = $(OBJ:.o=.d)

all: $(OBJ_DIR) libft $(NAME)

# Create the necessary subdirectories for object files
$(OBJ_DIR)/%.o: %.c libft/libft.a minilibx-linux/libmlx_Linux.a so_long.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(libft) -I$(minilibx)

-include $(DEPS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) -L$(libft) -lft $(mlx) -L$(minilibx) -lXext -lX11 -lmlx

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(mlx):
	make -C $(minilibx)

libft:
	make -C $(libft)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(libft) clean
	make -C $(minilibx) clean

fclean: clean
	rm -f $(NAME)
	make -C $(libft) fclean

re: fclean all

.PHONY: all clean fclean re libft