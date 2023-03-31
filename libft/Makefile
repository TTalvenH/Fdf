NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
VPATH = src
SRC = ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_strlen.c  \
	  ft_isprint.c ft_memset.c  ft_bzero.c   ft_memcpy.c  ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c  \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c  ft_memcmp.c  ft_strnstr.c \
	  ft_atoi.c    ft_calloc.c  ft_strdup.c  ft_substr.c  ft_strjoin.c \
	  ft_strtrim.c ft_split.c   ft_itoa.c    ft_strmapi.c ft_striteri.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c    \
	  ft_printf.c ft_printf_fd.c ft_strjoin_slash.c ft_free_array.c    \
	  get_next_line.c get_next_line_utils.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I./include -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
	