/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/30 20:13:29 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_local(const char *str);

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = -1;
	dup = malloc((ft_strlen_local(str) +1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (++i, str[i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

static int	ft_strlen_local(const char *str)
{
	int	len;

	len = -1;
	while (++len, str[len])
		;
	return (len);
}
