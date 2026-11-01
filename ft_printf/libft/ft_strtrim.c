/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:57 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/02 12:19:27 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = -1;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (++i, s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
	}
	while (++j, (len - j - 1) >= 0)
	{
		if (!ft_strchr(set, s1[len - j - 1]))
			break ;
	}
	return (ft_substr(s1, i, (len - j - 1) - i +1));
}
