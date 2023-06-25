# Program name
NAME = cub3D

# Source directories
STCDIR = srcs
SRC =		srcs/main.c \
			srcs/map_checker.c \
			srcs/ray_casting_dda.c

SRC_GNL =	srcs/get_next_line/get_next_line_bonus.c \
			srcs/get_next_line/get_next_line_utils_bonus.c

SRC_UTILS =	srcs/utils/utils1.c \
			srcs/utils/utils_print.c \
			srcs/utils/utils_free.c

# Variables
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g

# Include directories
INCDIR := include
INCLUDES := -I$(INCDIR)

# Libraries
LINKS = -lX11 -lXext -lm libft/libft.a

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

.PHONY: all clean fclean re