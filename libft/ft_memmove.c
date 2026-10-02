/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:04 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/02 12:22:49 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*tmp;

	i = -1;
	tmp = ft_calloc(n, sizeof(void *));
	while (++i, i < n)
		*((unsigned char *)tmp + i) = *((unsigned char *)src + i);
	i = -1;
	while (++i, i < n)
		*((unsigned char *)dest + i) = *((unsigned char *)tmp + i);
	free(tmp);
	return (dest);
}
