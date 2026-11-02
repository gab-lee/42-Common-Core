/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:28:52 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:28:58 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i, i < n)
	{
		if (*((unsigned char *)ptr + i) == (unsigned char)(c))
			return ((unsigned char *)ptr + i);
	}
	return (NULL);
}
