/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:59 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:30:00 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = -1;
	substr = malloc(len + 1 * sizeof(char));
	if (!substr)
		return (NULL);
	while (++i, i < len && (i + start) < ft_strlen(s))
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
