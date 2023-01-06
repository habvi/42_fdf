NAME		=	fdf

SRC			=	args.c \
				clear.c \
				color.c \
				debug.c \
				display.c \
				draw_line.c \
				draw_menu.c \
				exit.c \
				image.c \
				key.c \
				main.c \
				mouse.c \
				parse.c \
				parse2.c \
				read.c \
				rotate.c

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INCLUDE_DIR	=	./include/
INCLUDES	=	-I $(INCLUDE_DIR)

# unused
SRCS		=	$(addprefix $(SRC_DIR), $(SRC))

OBJS		=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
LIBFT		=	libft.a

# to do: -> cc
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-Lmlx_linux -lXext -lX11 -lm
MINILIBX	=	minilibx/libmlx_Linux.a

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX_FLAGS) $(MINILIBX)

$(LIBFT):
	$(MAKE) -C ./libft
	cp libft/$(LIBFT) $@

clean:
	$(RM) -r $(OBJ_DIR) libft/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) libft/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re
