/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_and_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:36 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:26:32 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char_count(char c, int *bytes_written)
{
	write(1, &c, 1);
	(*bytes_written)++;
}

void	put_str_count(char *s, int *bytes_written)
{
	int	i;

	i = -1;
	while (++i, s[i])
		put_char_count(s[i], bytes_written);
}
