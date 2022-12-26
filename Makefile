NAME		=	fdf

SRC			=	args.c \
				clear.c \
				debug.c \
				display_map.c \
				draw_map.c \
				main.c

SRC_DIR		=	./src/
OBJS_DIR	=	./obj/
INCLUDE_DIR	=	./include/
INCLUDES	=	-I $(INCLUDE_DIR)

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:%.c=%.o))
LIBFT		=	libft.a

# -> cc
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) -Lmlx_linux -lXext -lX11 -lm minilibx/libmlx_Linux.a

$(LIBFT):
	$(MAKE) -C ./libft
	cp libft/$(LIBFT) $@

clean:
	$(RM) -r $(OBJS_DIR) libft/$(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) libft/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re
