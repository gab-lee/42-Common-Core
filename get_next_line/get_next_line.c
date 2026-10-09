/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/08 22:36:19 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;
	int			res;

	line = NULL;
	if (stash)
		res = read_from_stash(fd, &line, &stash);
	else
		res = read_next_line(fd, &line, &stash);
	if (res == 0 && line && *line)
		return (line);
	else if (res == 1)
	{
		temp = ft_gnl_strjoin_andfree(line, "\n", &line);
		line = temp;
		return (line);
	}
	else
	{
		free(stash);
		free(line);
		stash = NULL;
		return (NULL);
	}
}

