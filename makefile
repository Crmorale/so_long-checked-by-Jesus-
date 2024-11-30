NAME = so_long

# Compilador y flags
CC = clang
CFLAGS = -g -Wall -Werror -Wextra \
		#-g -fsanitize=address,undefined \


# Directorios
MLX42_DIR = ./MLX42
MLX		= $(MLX42_DIR)/build/libmlx42.a
OBJ_DIR = obj
GNL_DIR = get_next_line

LINK	= -ldl -lglfw -lpthread -lm -fPIE

HEADERS = -I$(MLX42_DIR)

# Archivos fuente y objetos
SRC = 	so_long.c ft_check_map.c \
		ft_check_possibility.c ft_draw_map.c \
		ft_player_move.c ft_movement.c\
		ft_read_map.c ft_utils.c \

GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
GNL_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o)))

# Flags para MiniLibX
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm

# Incluir directorios
INCLUDES = -I$(MLX_DIR) -I$(GNL_DIR)

# REgla para objetos
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling So_long..."

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Reglas
all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_OBJ) $(MLX) $(LINK) $(HEADERS)


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx42