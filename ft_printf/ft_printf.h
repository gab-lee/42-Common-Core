/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:22:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/20 23:55:49 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define CONVERSIONS "cspdiuxX%"

int		ft_printf(const char *, ...);
void 	put_and_count(unsigned char c, int *bytes_written);
void	handle_conversion(const char *str, int *i, int *bytes_written);
//utility files
char	*ft_strchr(const char *str, int c);
char	*ft_strcat_char(char *str, char c);
size_t	ft_strlen_safe(const char *str);

#endif