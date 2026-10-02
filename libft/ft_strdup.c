/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/02 11:52:24 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = -1;
	dup = malloc((ft_strlen(str) +1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (++i, str[i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

