/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 23:10:55 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_modifier	call_modifier(char *flags)
{
	t_modifier	m;

	m = nothing;
	if (has_width(flags))
		m = handle_width(m);
	if (has_minus(flags))
		m = handle_minus(m);
	else (has_zero(flags))
		m = handle_zero(m);
	if (has_dot(flags))
		m = handle_dot(m);
	if (has_plus(flags)) //concats 0x with str
		m = handle_plus(m);
	else (has_space(flags))
		m = handle_space(m);
	if (has_hashtag(flags)) //concats 0x with str if handle is x ???
		m = handle_hashtag(m);
	return (m);
}