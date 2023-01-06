SRC			=	ft_atoi.c \
				ft_atox.c \
				ft_isdigit.c \
				ft_min.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_toupper.c \
				ft_lstadd_back.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstnew.c \
				get_next_line_utils.c \
				get_next_line.c

SRC_DIR		=	./src/
OBJS_DIR	=	./obj/
INCLUDE_DIR	=	./include/
INCLUDES	=	-I $(INCLUDE_DIR)

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:%.c=%.o))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs

NAME		=	libft.a

all: $(NAME)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
