NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
AR = ar rcs
LIBFT = libft/libft.a
RM = rm -f
COMMON_SRCS = handles/handle_c.c \
	handles/handle_d_or_i.c \
	handles/handle_p.c \
	handles/handle_percent.c \
	handles/handle_s.c \
	handles/handle_u.c \
	handles/handle_upper_x.c \
	handles/handle_x.c \
	handles/get_hexadecimal.c \
	parse/call_handle.c \
	parse/call_mandatory.c \
	utils/put_and_count.c \
	utils/safe_call.c \
	utils/ft_strcat_char.c \
	utils/str_shrink.c
SRCS = $(COMMON_SRCS) \
	ft_printf.c
BONUS_SRCS = $(COMMON_SRCS) \
	ft_printf_bonus.c \
	parse/call_bonus.c \
	utility/call_modifiers_bonus.c \
	parse/check_valid_flags.c \
	parse/extract_flags.c \
	parse/identify_flag.c \
	modifiers/modify_dot_bonus.c \
	modifiers/modify_hashtag_bonus.c \
	modifiers/modify_width_minus_bonus.c \
	modifiers/modify_plus_bonus.c \
	modifiers/modify_space_bonus.c \
	modifiers/modify_width_bonus.c \
	modifiers/modify_width_zero_bonus.c \
	modifiers/modifiers_utility_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): .mandatory

$(LIBFT):
	$(MAKE) -C libft

# mandatory and bonus both produce libftprintf.a (each with its own ft_printf),
# so each target rebuilds the archive from scratch and invalidates the other one.
# libft.a is the base of the archive so users only need to link -lftprintf.
.mandatory: $(LIBFT) $(OBJS)
	$(RM) $(NAME) .bonus
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@touch .mandatory

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJS)
	$(RM) $(NAME) .mandatory
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	@touch .bonus

%.o: %.c ft_printf.h ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS) $(BONUS_OBJS) .mandatory .bonus

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
