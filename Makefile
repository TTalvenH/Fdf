NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c multiply_matrix.c my_mlx_pixel_put.c line.c translate_vector.c map_size.c matrices.c
OBJ = $(SRC:.c=.o)

LIBFT = libft.a
OS = $(shell uname)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

ifeq ($(OS), Darwin)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
endif

ifeq ($(OS), Linux)
$(NAME): $(SRC)
	$(CC) $(SRC) ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/include -Ilibft -Llibft -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@
endif

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make clean -C libft

re: fclean all
	make fclean -C libft
