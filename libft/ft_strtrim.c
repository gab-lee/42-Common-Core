/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:29:57 by gabrlee           #+#    #+#             */
/*   Updated: 2026/09/28 17:29:58 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_instr(char c, const char *set);
static int	ft_count_kept(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	int		tsize;
	int		i;
	int		j;

	tsize = ft_count_kept(s1, set);
	tstr = malloc((ft_strlen(s1) - tsize + 1) * sizeof(char));
	if (!tstr)
		return (NULL);
	i = -1;
	j = 0;
	while (++i, s1[i])
	{
		if (!ft_instr(s1[i], set))
			tstr[j++] = s1[i];
	}
	tstr[j] = '\0';
	return (tstr);
}

static int	ft_count_kept(char const *s1, char const *set)
{
	int	i;
	int	tsize;

	i = -1;
	tsize = 0;
	while (++i, s1[i])
	{
		if (ft_instr(s1[i], set))
			tsize++;
	}
	return (tsize);
}

static int	ft_instr(char c, const char *set)
{
	int	i;

	i = -1;
	while (++i, set[i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}
