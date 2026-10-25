NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f
SRCS = ft_printf.c \
	handles/handle_c.c \
	handles/handle_conversion.c \
	handles/handle_d_or_i.c \
	handles/handle_flags.c \
	handles/handle_p.c \
	handles/handle_percent.c \
	handles/handle_s.c \
	handles/handle_u.c \
	handles/handle_upper_x.c \
	handles/handle_x.c \
	modifiers/modify_dot_bonus.c \
	modifiers/modify_hashtag_bonus.c \
	modifiers/modify_minus_bonus.c \
	modifiers/modify_plus_bonus.c \
	modifiers/modify_space_bonus.c \
	modifiers/modify_width_bonus.c \
	modifiers/modify_zero_bonus.c \
	modifiers/nothing.c \
	utility/format_str.c \
	utility/ft_printf_utility.c \
	utility/put_and_count.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
