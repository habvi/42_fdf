SRCS	= $(wildcard *.c) # todo
OBJDIR 	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCS:.c=.o))

CC		= clang
CFLAGS	= -Wall -Wextra -Werror

NAME	= fdf

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p obj

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
