# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagaudey <nagaudey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 18:18:42 by nagaudey          #+#    #+#              #
#    Updated: 2025/03/12 19:32:00 by nagaudey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -fPIC
LDFLAGS = -fPIE
CC = cc

LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx-linux
MLX = $(MINILIBX_DIR)/libmlx_Linux.a
LIBFT = $(LIBFT_DIR)/libft.a

SRC = libft/get_next_line/get_next_line.c libft/ft_split.c libft/ft_strchr2.c ft_render.c \
		end.c ft_set.c main.c ft_move.c ft_close.c ft_cutmap.c ft_check_path.c ft_clone_map.c \
		ft_put.c print_bonus.c ft_set_end.c ft_set_enemy.c ft_map_bonus.c ft_map.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
DEPS = $(OBJ:.o=.d)

all: $(LIBFT) $(MLX) $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: %.c so_long.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX) -L$(MINILIBX_DIR) -lXext -lX11 -lmlx

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
