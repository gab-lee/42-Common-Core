/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:06:06 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 22:59:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(char *str, va_list *args, int *bytes_written, void (*flags)(char *))
{
	int		c;

	c = va_arg(*args, int);
	put_char_count((char)c, bytes_written);
}
