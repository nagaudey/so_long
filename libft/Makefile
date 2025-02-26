NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

HEADERS = all.h
OBJ_DIR = obj

LIBFT_FILES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcat.c ft_strncmp.c \
 ft_tolower.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c \
 ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c \
 ft_strlen.c ft_strrchr.c ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c

PRINTF_FILES = ft_printf/ft_len_putaddress.c ft_printf/ft_len_putchar.c ft_printf/ft_len_putnbr_hex.c \
 ft_printf/ft_len_putnbr.c ft_printf/ft_len_putstr.c ft_printf/ft_len_uputnbr.c ft_printf/ft_printf.c ft_printf/ft_iterative_count.c

GNL_FILES = get_next_line/get_next_line.c get_next_line/get_next_line_bonus.c \

LIBFT_BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c \
 ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstadd_back_bonus.c ft_lstmap_bonus.c

SRC_FILES = $(LIBFT_FILES) $(PRINTF_FILES) $(GNL_FILES)
BONUS_SRC_FILES = $(SRC_FILES) $(LIBFT_BONUS_FILES)

OBJ_FILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
BONUS_OBJ_FILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(BONUS_SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

bonus: $(BONUS_OBJ_FILES)
	$(AR) $(NAME) $^

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
