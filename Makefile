NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = main.o my_mlx_pixel_put.o line.o translate_vector.o
LIBFT = libft.a
OS = $(shell uname)

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

ifeq ($(OS), Darwin)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
endif

ifeq ($(OS), Linux)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/include -Imlx_linux -Llibft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
endif

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
