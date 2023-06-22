NAME = cub3D

SRC = srcs/main.c srcs/map_checker.c
SRC_GNL = srcs/get_next_line/get_next_line_bonus.c srcs/get_next_line/get_next_line_utils_bonus.c
SRC_UTILS = srcs/utils/utils1.c srcs/utils/utils_print.c srcs/utils/utils_free.c

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g

LINKS = -lX11 -lXext -lm libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(SRC_GNL) $(SRC_UTILS)
	@ make bonus -s -C libft/
	@ $(CC) $(CFLAGS) $(SRC) $(SRC_GNL) $(SRC_UTILS) $(LINKS) -o $(NAME)

clean:
	@ make clean -s -C libft/
	@ $(RM)

fclean:
	@ make fclean -s -C libft/
	@ $(RM) $(NAME)

re: fclean all