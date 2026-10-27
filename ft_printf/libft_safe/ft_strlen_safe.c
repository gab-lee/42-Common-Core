/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:04:50 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/26 13:22:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_safe(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = -1;
	while (len++, str[len])
		;
	return (len);
}
