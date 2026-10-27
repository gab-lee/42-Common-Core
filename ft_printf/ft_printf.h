/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:22:10 by gabrlee          ###   ########.fr       */
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
typedef int	(*t_modifier)(char **str, char handle, int width, int precision);
typedef char	*(*t_handler)(va_list *args);

int		ft_printf(const char *str, ...);
void	put_char_count(char c, int *bytes_written);
void	put_str_count(char *s, int *bytes_written);

//hanldes
int		handle_conversion(const char *str, int *i, int *bytes_written, va_list *args);
int		call_modifier(char **str, char *flags, char handle);
char	*handle_c(va_list *args);
char	*handle_s(va_list *args);
char	*handle_p(va_list *args);
char	*handle_d_or_i(va_list *args);
char	*handle_u(va_list *args);
char	*handle_x(va_list *args);
char	*handle_upper_x(va_list *args);

//Modifiers
int	nothing(char **str, char handle, int width, int precision);
int	modify_width(char **str, char handle, int width, int precision);
int	modify_dot(char **str, char handle, int width, int precision);
int	modify_hashtag(char **str, char handle, int width, int precision);
int	modify_width_zero(char **str, char handle, int width, int precision);
int	modify_width_minus(char **str, char handle, int width, int precision);
int	modify_plus(char **str, char handle, int width, int precision);
int	modify_space(char **str, char handle, int width, int precision);

int	ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strcat_char(char *str, char c);
size_t	ft_strlen_safe(const char *str);
//formatstr
char	*get_hexadecimal(unsigned long x, int upper);
char	*strjoin_safe(char const *s1, char const *s2);
size_t	str_shrink(char **str, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

#endif