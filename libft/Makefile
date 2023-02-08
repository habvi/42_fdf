NAME		:=	libft.a

SRC_DIR		:=	src
SRCS		:=	ft_atoi.c \
				ft_atox.c \
				ft_isdigit.c \
				ft_max.c \
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
				get_next_line.c \
				ft_printf.c \
				handle_info.c \
				parse_format.c \
				convert_to_str.c \
				convert_to_str2.c \
				strdup_for_printf.c \
				itoa_utoa_for_printf.c\
				ptoa_xtoa_for_printf.c \
				set_field.c \
				set_output.c

OBJ_DIR		:=	obj
OBJS		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDE_DIR	:=	include
INCLUDES	:=	-I./$(INCLUDE_DIR)/

DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
ARFLAGS		:=	rcs
MKDIR		:=	mkdir -p

all: $(NAME)

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
