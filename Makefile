NAME = cub3D
SRC = srcs/main.c

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

LINKS = -lx11 -lXext -lm

all: $(NAME)

$(NAME): $(SRC)
	@ $(CC) $(CFLAGS) $(SRC) $(LINKS) -o $(NAME)

clean:
	@ $(RM)

fclean:
	@ $(RM) $(NAME)

re: fclean all