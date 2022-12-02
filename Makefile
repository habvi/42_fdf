SRCS		= $(wildcard *.c) # todo
OBJS_DIR	= ./objs/
# OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS		= $(SRCS:%.c=$(OBJS_DIR)%.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

NAME		= fdf

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p objs

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
