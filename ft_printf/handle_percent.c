/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:05:52 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/21 15:36:47 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_percent(char *str, va_list *args, int *bytes_written, void (*flags)(char *))
{
	(void) args;
	put_char_count('%', bytes_written);
}