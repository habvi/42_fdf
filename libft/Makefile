SRC_FT_PRINTF	:=	ft_printf/convert_to_str.c \
					ft_printf/convert_to_str2.c \
					ft_printf/ft_printf.c \
					ft_printf/handle_info.c \
					ft_printf/itoa_utoa_for_printf.c\
					ft_printf/parse_format.c \
					ft_printf/ptoa_xtoa_for_printf.c \
					ft_printf/set_field.c \
					ft_printf/set_output.c \
					ft_printf/strdup_for_printf.c

SRC_GNL			:=	get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line.c

SRC_LIBFT		:=	libft/ft_atoi.c \
					libft/ft_atox.c \
					libft/ft_isdigit.c \
					libft/ft_max.c \
					libft/ft_min.c \
					libft/ft_split.c \
					libft/ft_strchr.c \
					libft/ft_strdup.c \
					libft/ft_strlcpy_void.c \
					libft/ft_strlcpy.c \
					libft/ft_strlen.c \
					libft/ft_strncmp.c \
					libft/ft_strndup.c \
					libft/ft_strnlen.c \
					libft/ft_toupper.c

SRC_LIST		:=	list/ft_lstadd_back.c \
					list/ft_lstclear.c \
					list/ft_lstdelone.c \
					list/ft_lstiter.c \
					list/ft_lstlast.c \
					list/ft_lstnew.c

SRC_DIR			:=	src
SRCS			:=	$(SRC_FT_PRINTF) $(SRC_GNL) $(SRC_LIBFT) $(SRC_LIST)

OBJ_DIR			:=	obj
OBJS			:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDE_DIR		:=	include
INCLUDES		:=	-I./$(INCLUDE_DIR)/

DEPS			:=	$(OBJS:.o=.d)

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -MMD -MP
ARFLAGS			:=	rcs
MKDIR			:=	mkdir -p
# RMDIR			:=	rmdir

NAME			:=	libft.a

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

debug:
	$(info >>> default goal : $(.DEFAULT_GOAL))
	$(info >>> name : $(NAME))
	$(info >>> srcs : $(SRCS))
	$(info >>> objs : $(OBJS))

.PHONY: all clean fclean re debug
