# Program name
NAME = cub3D

# Source directories
STCDIR = srcs
SRC =		srcs/main.c \
			srcs/map_checker.c \
			srcs/ray_init.c \
			srcs/ray_casting_dda.c \
			srcs/minimap.c \
			srcs/read_file.c \
			srcs/draw_on_image.c \
			srcs/animations.c \
			srcs/texture.c \
			srcs/event/key_hook.c \
			srcs/event/ft_update.c \

SRC_GNL =	srcs/get_next_line/get_next_line_bonus.c \
			srcs/get_next_line/get_next_line_utils_bonus.c

SRC_UTILS =	srcs/utils/utils1.c \
			srcs/utils/utils_print.c \
			srcs/utils/utils_free.c \
			srcs/utils/utils_vector.c

# Variables
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g

# Include directories
INCDIR := include
INCLUDES := -I$(INCDIR)

# Libraries
LINKS = minilibx-linux/libmlx.a libft/libft.a -lX11 -lXext -lm 

all: $(NAME)

$(NAME): $(SRC) $(SRC_GNL) $(SRC_UTILS)
	@ make bonus -s -C libft/
	@ $(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(SRC_GNL) $(SRC_UTILS) $(LINKS) -o $(NAME)

clean:
	@ make clean -s -C libft/
	@ $(RM)

fclean:
	@ make fclean -s -C libft/
	@ $(RM) $(NAME)

re: fclean all

exe: all
	@ ./$(NAME) ./maps/maze.cub

valgrind: all
	@ valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ./maps/map1.cub

norminette:
	@ norminette ./srcs

.PHONY: all clean fclean re exe valgrind norminette