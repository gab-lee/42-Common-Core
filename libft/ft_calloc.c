/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:24:04 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 22:42:46 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero_local(void *ptr, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero_local(ptr, count * size);
	return (ptr);
}

static void	ft_bzero_local(void *ptr, size_t n)
{
	size_t	i;

	i = -1;
	while (++i, i < n)
		*((unsigned char *)ptr + i) = (char)(0);
}
