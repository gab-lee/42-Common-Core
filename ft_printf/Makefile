NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f
COMMON_SRCS = ft_printf.c \
	handles/handle_c.c \
	handles/handle_d_or_i.c \
	handles/handle_p.c \
	handles/handle_percent.c \
	handles/handle_s.c \
	handles/handle_u.c \
	handles/handle_upper_x.c \
	handles/handle_x.c \
	utility/call_handle.c \
	utility/call_bonus.c \
	utility/call_mandatory.c \
	libft_safe/ft_atoi.c \
	libft_safe/ft_strcat_char.c \
	libft_safe/get_hexadecimal.c \
	libft_safe/put_and_count.c \
	libft_safe/str_shrink.c \
	libft_safe/ft_strchr.c \
	libft_safe/ft_strlcpy.c \
	libft_safe/ft_strlen_safe.c \
	libft_safe/strjoin_safe.c \
	modifiers/call_modifiers_bonus.c \
	modifiers/modify_dot_bonus.c \
	modifiers/modify_hashtag_bonus.c \
	modifiers/modify_width_minus_bonus.c \
	modifiers/modify_plus_bonus.c \
	modifiers/modify_space_bonus.c \
	modifiers/modify_width_bonus.c \
	modifiers/modify_width_zero_bonus.c \
	modifiers/nothing_bonus.c
OBJS = $(COMMON_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: all

%.o: %.c ft_printf.h ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
