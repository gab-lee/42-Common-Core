/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:22:10 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

# undef BONUS
# define BONUS 1
# define FLAGS "-0.# +"

//types
typedef int	(*t_modifier)(char **str, char handle, int width, int precision);

//calls
int	call_bonus(const char *str, int *i, int *bytes_written, va_list *args);

//flags
int	has_zero(char *flags);
int	has_space(char *flags);
int	has_minus(char *flags);
int	has_plus(char *flags);
int	has_hash(char *flags);
int	check_valid_flags(char *flags);

//Modifiers
int	call_modifier(char **str, char *flags, char handle);
int	nothing(char **str, char handle, int width, int precision);
int	modify_width(char **str, char handle, int width);
int	modify_dot(char **str, char handle, int precision);
int	modify_hashtag(char **str, char handle, int has_hash);
int	modify_width_zero(char **str, char handle, int width);
int	modify_width_minus(char **str, char handle, int width);
int	modify_plus(char **str, char handle);
int	modify_space(char **str, char handle);

#endif
