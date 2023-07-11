# Program name
NAME = cub3D

# Source directories
STCDIR = srcs
SRCS =		srcs/main.c \
			srcs/init.c \
			srcs/map_checker.c \
			srcs/map_checker_01.c \
			srcs/map_checker_02.c \
			srcs/ray_init.c \
			srcs/ray_casting_dda.c \
			srcs/minimap.c \
			srcs/read_file.c \
			srcs/draw_on_image.c \
			srcs/animations.c \
			srcs/texture.c \
			srcs/event/input_press.c \
			srcs/event/input_release.c \
			srcs/event/ft_update.c \
			srcs/event/easter_egg.c \
			srcs/get_next_line/get_next_line_bonus.c \
			srcs/get_next_line/get_next_line_utils_bonus.c \
			srcs/utils/utils1.c \
			srcs/utils/utils_print.c \
			srcs/utils/utils_free.c \
			srcs/utils/utils_vector.c

OBJS	=	$(SRCS:.c=.o)

# Variables
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g

# Include directories
INCDIR := include
INCLUDES := -I$(INCDIR)
HEADER := $(INCDIR)/cub3D.h

# Libraries
LINKS = minilibx-linux/libmlx.a libft/libft.a -lX11 -lXext -lm 

all: $(NAME)

$(NAME): $(OBJS)
	@ make bonus -s -C libft/
	@ $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKS) -o $(NAME)

%.o: %.c $(HEADER)
	@ $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ make clean -s -C libft/
	@ $(RM) $(OBJS)

fclean: clean
	@ make fclean -s -C libft/
	@ $(RM) $(NAME)

re: fclean all

exe: all
	@ ./$(NAME) ./maps/maze.cub

valgrind: all
	@ valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ./maps/maze.cub

norminette:
	@ norminette ./srcs

.PHONY: all clean fclean re exe valgrind norminette