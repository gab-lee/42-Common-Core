/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_modifiers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/04 11:05:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fill_props(int *props, char *flags, int width, int precision);

//order here is the order of application and must match t_mod in the header
static const t_modifier	g_modifiers[] = {
modify_dot,
modify_plus,
modify_space,
modify_hashtag,
modify_width_minus,
modify_width_zero,
modify_width,
NULL
};

int	call_modifier(char **str, char *flags, char handle)
{
	int	props[MOD_COUNT];
	int	width;
	int	precision;
	int	res;
	int	i;

	res = extract_flags(flags, &width, &precision);
	if (res == 0)
		fill_props(props, flags, width, precision);
	i = -1;
	while (++i, res == 0 && g_modifiers[i])
		res = g_modifiers[i](str, handle, props[i]);
	free(flags);
	return (res);
}

static void	fill_props(int *props, char *flags, int width, int precision)
{
	props[MOD_DOT] = precision;
	props[MOD_PLUS] = has_plus(flags);
	props[MOD_SPACE] = has_space(flags) && !has_plus(flags);
	props[MOD_HASH] = has_hash(flags);
	props[MOD_MINUS] = -1;
	props[MOD_ZERO] = -1;
	props[MOD_WIDTH] = -1;
	if (has_minus(flags))
		props[MOD_MINUS] = width;
	else if (has_zero(flags))
		props[MOD_ZERO] = width;
	else
		props[MOD_WIDTH] = width;
}
