/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:05 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/27 22:55:40 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_entry	g_handlers[] = {
{'c', handle_c},
{'s', handle_s},
{'p', handle_p},
{'d', handle_d_or_i},
{'i', handle_d_or_i},
{'u', handle_u},
{'x', handle_x},
{'X', handle_upper_x},
{'%', handle_percent},
{0, NULL}
};

t_handler	call_handle(char c)
{
	int	i;

	i = -1;
	while (++i, g_handlers[i].fn)
		if (g_handlers[i].key == c)
			return (g_handlers[i].fn);
	return (NULL);
}
