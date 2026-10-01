/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:36 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/01 11:34:11 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;

	i = -1;
	dest_len = ft_strlen(dest);
	if (n < dest_len)
		return (n + ft_strlen(src));
	while (*dest)
		dest++;
	while (++i, src[i] && n > 0 && (dest_len + i < (n - 1)))
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest_len + ft_strlen(src));
}
