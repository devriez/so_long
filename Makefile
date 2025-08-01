
CC = cc
NAME = 	so_long

#Sources
SRC_DIR = ./src
SRCS_MAIN = $(SRC_DIR)/so_long.c
SRCS = 		$(SRC_DIR)/free_and_error.c \
			$(SRC_DIR)/player_move.c \
			$(SRC_DIR)/check_map.c \
			$(SRC_DIR)/init_map.c \
			$(SRC_DIR)/init_game_and_sprites.c \
			$(SRC_DIR)/validate_path.c \

#Includes
INCLUDES = -I./include

#Utils
UTILS_DIR = ./utils
UTILS = $(UTILS_DIR)/ft_strappend.c 

# AddressSanitizer
SANITIZE_FLAGS = -fsanitize=address

# MiniLibX flags
MLX_DIR = ./minilibx-linux
MINILIBX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11

# Libft flags
LIBFT_DIR = ./libft
LIBFT_INCLUDES = -I$(LIBFT_DIR)
LIBFT_A = $(LIBFT_DIR)/libft.a

# get_next_line flags
GNL_DIR = ./utils/get_next_line
GNL_INCLUDES = -I$(GNL_DIR)
GNL = 		$(GNL_DIR)/get_next_line_utils.c \
			$(GNL_DIR)/get_next_line.c 

all: $(NAME)

$(LIBFT_A):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(LIBFT_A)
		$(CC) $(SRCS_MAIN) $(SRCS) $(UTILS) $(INCLUDES) \
		$(LIBFT_A) $(LIBFT_INCLUDES) \
		$(GNL) $(GNL_INCLUDES) \
		$(MINILIBX_FLAGS) $(SANITIZE_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C  $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
	./$(NAME) assets/maps/valid/map3.ber


TESTS_MAIN = ./tests/tests.c
TESTS_NAME = tests_results

test: $(LIBFT_A)
	$(CC) $(TESTS_MAIN) $(SRCS) $(LIBFT_A) $(INCLUDES) $(LIBFT_INCLUDES) $(MINILIBX_FLAGS) -o $(TESTS_NAME)
	./$(TESTS_NAME)
