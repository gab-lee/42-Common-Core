/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:49 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:52:18 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(char *str, va_list *args, int *bytes_written)
{
	char	*s;

	s = va_arg(*args, char *);
	put_str_count(s, bytes_written);
}