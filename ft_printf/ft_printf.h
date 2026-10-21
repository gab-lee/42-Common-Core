/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:28:04 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define CONVERSIONS "cspdiuxX%"

typedef void (*t_handler)(char *str, va_list *args, int *bytes_written);
typedef void (*t_modifier)(char *str);

int		ft_printf(const char *str, ...);
void	put_char_count(char c, int *bytes_written);
void	put_str_count(char *s, int *bytes_written);
void	handle_conversion(const char *str, int *i, int *bytes_written, va_list *args);
void	handle_c(char *str, va_list *args, int *bytes_written);
void	handle_s(char *str, va_list *args, int *bytes_written);
void	handle_p(char *str, va_list *args, int *bytes_written);
void	handle_d_or_i(char *str, va_list *args, int *bytes_written);
void	handle_u(char *str, va_list *args, int *bytes_written);
void	handle_x(char *str, va_list *args, int *bytes_written);
void	handle_upper_x(char *str, va_list *args, int *bytes_written);
//utility files
char	*ft_strchr(const char *str, int c);
char	*ft_strcat_char(char *str, char c);
size_t	ft_strlen_safe(const char *str);

#endif