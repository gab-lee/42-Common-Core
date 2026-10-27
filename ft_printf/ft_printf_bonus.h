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

//types
typedef int	(*t_modifier)(char **str, char handle, int width, int precision);

//Modifiers
int	nothing(char **str, char handle, int width, int precision);
int	modify_width(char **str, char handle, int width, int precision);
int	modify_dot(char **str, char handle, int width, int precision);
int	modify_hashtag(char **str, char handle, int width, int precision);
int	modify_width_zero(char **str, char handle, int width, int precision);
int	modify_width_minus(char **str, char handle, int width, int precision);
int	modify_plus(char **str, char handle, int width, int precision);
int	modify_space(char **str, char handle, int width, int precision);

#endif
