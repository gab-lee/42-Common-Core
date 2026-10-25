/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:27:41 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/22 17:31:00 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_modifier	call_modifier(char *flags, char handle)
{
	t_modifier	m;

	m = nothing;//do nothing to the string
	if (plus)
	{
		m = modify_plus(m, handle, 0);
	}
	else if (has_space(flags))
		m = modify_space(m, handle, 0);
	width = get_width(flags);
	if (width)
	{
		if (has_zero(flags))
			//pad with zero [sign][zero][space]
		else if (has_minus(flags))
			//left justify [sign][number][space]
		else
			//pad with space [space][sign][number]
	}


	if (has_dot(flags))
		m = modify_dot(m, handle, width);
	if (has_hashtag(flags)) //concats 0x with str if handle is x ???
		m = modify_hashtag(m, handle, width);
	return (m);
}
