# Program name
NAME = cub3D

# Source directories
SRCDIR = srcs srcs/event srcs/get_next_line srcs/utils
OBJDIR = .obj
SRC =		srcs/main.c \
			srcs/map_checker.c \
			srcs/ray_casting_dda.c \
			srcs/draw_on_image.c \
			srcs/minimap.c \
			srcs/event/key_hook.c \
			srcs/event/ft_update.c \

SRC_GNL =	srcs/get_next_line/get_next_line_bonus.c \
			srcs/get_next_line/get_next_line_utils_bonus.c

SRC_UTILS =	srcs/utils/utils1.c \
			srcs/utils/utils_print.c \
			srcs/utils/utils_free.c \
			srcs/utils/utils_vector.c

SRCS = $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c))
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCDIR)))

# Object files



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

$(NAME): $(OBJ)
	@ make bonus -s -C libft/
	@ $(CC) $(CFLAGS) $(INCLUDES) $^ $(LINKS) -o $@

$(OBJDIR)/%.o: $(foreach dir, $(SRCDIR),$(dir)/%.c) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@ make clean -s -C libft/
	@ $(RM) $(OBJDIR)

fclean:
	@ make fclean -s -C libft/
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re