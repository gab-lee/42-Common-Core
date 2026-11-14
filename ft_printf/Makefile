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
	utility/put_and_count.c \
	utility/safe_call.c \
	utility/ft_strcat_char.c \
	utility/str_shrink.c
SRCS = $(COMMON_SRCS) \
	ft_printf.c
BONUS_SRCS = $(COMMON_SRCS) \
	ft_printf_bonus.c \
	parse/call_bonus.c \
	parse/call_modifiers_bonus.c \
	parse/check_valid_flags_bonus.c \
	parse/extract_flags_bonus.c \
	parse/has_flag_bonus.c \
	parse/put_null_bonus.c \
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

# always ask libft's own Makefile; libft.a only changes (and triggers a
# relink here) when one of its sources actually changed.
$(LIBFT): FORCE
	@$(MAKE) -C libft

FORCE:

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

%.o: %.c ft_printf.h ft_printf_bonus.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS) $(BONUS_OBJS) .mandatory .bonus

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
