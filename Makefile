NAME		:=	fdf

SRC_DIR		:=	src
SRCS		:=	args.c \
				clear.c \
				color.c \
				convert.c \
				display.c \
				draw_line.c \
				draw_menu.c \
				exit.c \
				image.c \
				key_operation.c \
				key.c \
				main.c \
				mouse.c \
				parse.c \
				read.c \
				rotate.c \
				set_data.c \
				set_point.c

OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

LIBFT_DIR	:=	libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

# set
MLX_DIR		:=	minilibx
MLX_FLAGS	:=	-Lmlx_linux -lXext -lX11 -lm
MINILIBX	:=	$(MLX_DIR)/libmlx_Linux.a

INCLUDE_DIR	:=	include
INCLUDES	:=	-I./$(INCLUDE_DIR)/ -I$(LIBFT_DIR)/$(INCLUDE_DIR)/ -I$(MLX_DIR)/ -I.

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
MKDIR		:=	mkdir -p

all: $(NAME)

bonus: all

-include $(DEPS)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS)

clean:
	$(RM) -r $(OBJ_DIR) $(LIBFT_DIR)/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

clone:
	git clone https://github.com/42Paris/minilibx-linux $(MLX_DIR)

norm:
	norminette $(SRC_DIR) $(INCLUDE_DIR) $(LIBFT_DIR)

FORCE:

.PHONY: all clean fclean re bonus FORCE norm clone
