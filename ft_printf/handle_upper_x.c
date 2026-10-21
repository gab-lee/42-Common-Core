/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_upper_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:43 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 16:10:43 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_upper_x(char *str, va_list *args, int *bytes_written)
{
	char	*formatted_str;
	unsigned int x;
	
	x = va_arg(*args, unsigned int);
	formatted_str = ft_toupper(get_hexadecimal(x));
	put_str_count(formatted_str, bytes_written);
}