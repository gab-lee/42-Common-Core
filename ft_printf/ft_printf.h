/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 23:07:15 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define CONVERSIONS "cspdiuxX%"
# define HEXADECIMAL "0123456789abcdef"

//types
typedef char	*(*t_handler)(char *str, va_list *args, int *bytes_written, t_modifier *flags);
typedef char	*(*t_modifier)(char *str, char handle, int width);

int		ft_printf(const char *str, ...);
void	put_char_count(char c, int *bytes_written);
void	put_str_count(char *s, int *bytes_written);

//hanldes
int		handle_conversion(const char *str, int *i, int *bytes_written, va_list *args);
char	*handle_c(char *str, va_list *args, int *bytes_written, t_modifier *flags);
char	*handle_s(char *str, va_list *args, int *bytes_written, t_modifier *flags);
char	*handle_p(char *str, va_list *args, int *bytes_written, t_modifier *flags);
char	*handle_d_or_i(char *str, va_list *args, int *bytes_written, t_modifier *flags);
char	*handle_u(char *str, va_list *args, int *bytes_written, t_modifier *flags);
char	*handle_x(char *str, va_list *args, int *bytes_written, t_modifier *flags);
char	*handle_upper_x(char *str, va_list *args, int *bytes_written, t_modifier *flags);

//Modifiers
char	*nothing(char *str, char handle, int width);
char	*modify_width(char *str, char handle, int width);
char	*modify_dot(char *str, char handle, int width);
char	*modify_hashtag(char *str, char handle, int width);
char	*modify_zero(char *str, char handle, int width);
char	*modify_minus(char *str, char handle, int width);
char	*modify_plus(char *str, char handle, int width);
char	*modify_space(char *str, char handle, int width);

char	*ft_strchr(const char *str, int c);
char	*ft_strcat_char(char *str, char c);
size_t	ft_strlen_safe(const char *str);
static char	*ft_itoa(int n);
//formatstr
char	*get_hexadecimal(unsigned long x, int upper);
char	*ft_strjoin(char const *s1, char const *s2);

#endif