/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_and_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:36 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/04 10:51:53 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char c, int *bytes_written)
{
	write(1, &c, 1);
	(*bytes_written)++;
}

void	put_str(char *s, int len, int *bytes_written)
{
	int	i;

	i = -1;
	while (++i < len)
		put_char(s[i], bytes_written);
}
