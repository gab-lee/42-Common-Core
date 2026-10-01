/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:59 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/01 00:28:19 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	remaining;
	size_t	copy_len;

	i = -1;
	if (start > ft_strlen(s))
		remaining = 0;
	else
		remaining = ft_strlen(s) - start;
	copy_len = remaining;
	if (len < remaining)
		copy_len = len;
	substr = malloc((copy_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (++i, i < copy_len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
