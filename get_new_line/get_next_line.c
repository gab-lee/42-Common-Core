/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/03 10:58:24 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	static char	*stash;
	char		*line;
	int			res;

	if (stash)
		res = read_from_stash(fd, &line, &stash);
	else
		res = read_next_line(fd, &line, &stash);
	if (res == 0 || res == -1)
		return (NULL);
	line = ft_strjoin(line, '\n');
	return (line);
}
