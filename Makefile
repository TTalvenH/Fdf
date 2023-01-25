NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c matrix.c line.c get_size.c matrices.c data_init.c draw.c color.c utils.c events.c key_check.c
OBJ = $(SRC:.c=.o)

LIBFT = libft.a
OS = $(shell uname)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

ifeq ($(OS), Darwin)
$(NAME): $(SRC)
	$(CC) $(SRC) ./libft/libft.a -lmlx -Ilibft -Llibft -framework OpenGL -framework AppKit -lm -g -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -O3 -c $< -o $@
endif

ifeq ($(OS), Linux)
$(NAME): $(SRC)
	$(CC) $(SRC) ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/include -Ilibft -Llibft -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@
endif

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
