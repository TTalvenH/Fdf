NAME = fdf
NAME_BONUS = fdf_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c matrix.c line.c get_size.c matrices.c data_init.c draw.c color.c utils.c events.c key_check.c
SRC_BONUS = main_bonus.c matrix_bonus.c line_bonus.c get_size_bonus.c matrices_bonus.c data_init_bonus.c draw_bonus.c color_bonus.c utils_bonus.c events_bonus.c key_check_bonus.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a
OS = $(shell uname)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

ifeq ($(OS), Darwin)
$(NAME): $(SRC)
	$(CC) $(SRC) ./libft/libft.a -lmlx -Ilibft -Llibft -framework OpenGL -framework AppKit -lm -O3 -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -O3 -c $< -o $@
endif

ifeq ($(OS), Linux)
$(NAME): $(SRC)
	$(CC) $(SRC) ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/include -Ilibft -Llibft -Imlx_linux -lXext -lX11 -lm -lz -O3 -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@
endif

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libft

re: fclean all

bonus: fclean $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(SRC_BONUS)
	$(CC) $(SRC_BONUS) ./libft/libft.a -lmlx -Ilibft -Llibft -framework OpenGL -framework AppKit -lm -O3 -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -O3 -c $< -o $@
