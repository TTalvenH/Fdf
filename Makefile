NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD
VPATH = src
SRC = main.c matrix.c line.c get_size.c matrices.c data_init.c draw.c color.c utils.c events.c key_check.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(OBJ:.o=.d)
LIBFT = libft.a
OS = $(shell uname)

all: $(NAME)

$(LIBFT):
	make -C libft

ifeq ($(OS), Darwin)
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) ./libft/libft.a -lmlx -Ilibft -Llibft -framework OpenGL -framework AppKit -lm -O3 -o $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@
endif

ifeq ($(OS), Linux)
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/include -Ilibft -Llibft -Imlx_linux -lXext -lX11 -lm -lz -O3 -o $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I./include -I./libft/include -I/usr/include -Imlx_linux -c $< -o $@
endif

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libft

re: fclean all
