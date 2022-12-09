NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = main.o my_mlx_pixel_put.o line.o
all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
