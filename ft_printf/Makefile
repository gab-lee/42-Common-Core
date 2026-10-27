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
	utility/format_str.c \
	utility/get_hexadecimal.c \
	utility/ft_printf_utility.c \
	utility/put_and_count.c \
	libft_safe/ft_atoi.c \
	libft_safe/ft_strchr.c \
	libft_safe/ft_strlcpy.c \
	libft_safe/ft_strlen_safe.c \
	libft_safe/strjoin_safe.c
SRCS = $(COMMON_SRCS) utility/handle_conversion.c
BONUS_SRCS = $(COMMON_SRCS) \
	utility/handle_conversion_bonus.c \
	utility/call_modifiers_bonus.c \
	modifiers/modify_dot_bonus.c \
	modifiers/modify_hashtag_bonus.c \
	modifiers/modify_width_minus_bonus.c \
	modifiers/modify_plus_bonus.c \
	modifiers/modify_space_bonus.c \
	modifiers/modify_width_bonus.c \
	modifiers/modify_width_zero_bonus.c \
	modifiers/nothing_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

# mandatory and bonus both define handle_conversion, so each target rebuilds
# the archive from scratch and invalidates the other one
$(NAME): $(OBJS)
	$(RM) $(NAME) .bonus
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(BONUS_OBJS)
	$(RM) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	@touch .bonus
	@$(RM) utility/handle_conversion.o

%.o: %.c ft_printf.h ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
