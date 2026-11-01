/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:38 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/02 11:57:00 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!n)
		return (ft_strlen(src));
	while (++i, src[i] && i < (n - 1))
		dest[i] = src[i];
	dest[i] = '\0';
	return (ft_strlen(src));
}
