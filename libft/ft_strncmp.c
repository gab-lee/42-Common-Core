/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:46 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:29:47 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (!n)
		return (0);
	while (++i, i < (n - 1) && s1[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
