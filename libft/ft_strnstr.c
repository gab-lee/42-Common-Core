/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:51 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:29:53 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!needle || *needle == '\0')
		return ((char *)haystack);
	while (++i, haystack[i] && i < n)
	{
		if (haystack[i] == needle[j])
		{
			while (++j, i + j < n && needle[j] && haystack[i + j] == needle[j])
				;
			if (!needle[j])
				return ((char *)&haystack[i]);
			else
				j = 0;
		}
	}
	return (NULL);
}
