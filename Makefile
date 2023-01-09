NAME		=	fdf

SRC			=	args.c \
				clear.c \
				color.c \
				convert.c \
				display.c \
				draw_line.c \
				draw_menu.c \
				exit.c \
				image.c \
				key.c \
				main.c \
				mouse.c \
				parse.c \
				read.c \
				rotate.c \
				set_data.c

SRC_DIR		=	./src/
# SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJ_DIR		=	./obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

LIBFT_DIR	=	libft
LIBFT		=	libft.a

# set
MLX_DIR		=	minilibx

INCLUDE_DIR	=	include
INCLUDES	=	-I./$(INCLUDE_DIR)/ -I$(LIBFT_DIR)/$(INCLUDE_DIR)/ -I$(MLX_DIR)/

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-Lmlx_linux -lXext -lX11 -lm
MINILIBX	=	$(MLX_DIR)/libmlx_Linux.a

all: $(NAME)

bonus: all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C ./$(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $@

clean:
	$(RM) -r $(OBJ_DIR) libft/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) libft/$(LIBFT)

re: fclean all

norm:
	norminette $(SRC_DIR) $(INCLUDE_DIR) $(LIBFT_DIR)

.PHONY: all clean fclean re bonus norm
