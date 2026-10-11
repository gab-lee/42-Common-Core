/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/11 10:27:50 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;
	char		*newline;
	int			res;

	line = NULL;
	temp = ft_strjoin_safe(stash, NULL);
	newline = ft_strchr_safe(temp, '\n');
	if (newline)
	{
		*newline = '\0';
		line = ft_strjoin_safe(temp, "\n");
		if (stash)
			free(stash);
		stash = ft_strjoin_safe(newline + 1, NULL);
		if (temp)
			free(temp);
		return (line);
	}
	res = read_next_line(fd, &stash);
	if (res > 0)
	{
		if (temp)
			free(temp);
		if (line)
			free(line);
		return (get_next_line(fd));
	}
	if (res == 0 && stash && *stash)
	{
		line = ft_strjoin_safe(stash, "");
		free(stash);
		stash = NULL;
		free (temp);
		return (line);
	}
	if (temp)
		free(temp);
	if (line)
		free(line);
	if (stash)
	{
		free(stash);
		stash = NULL;
	}
	return (NULL);
}
