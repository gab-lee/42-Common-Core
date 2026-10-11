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
	temp = ft_strjoin(stash, NULL);
	newline = ft_gnl_strchr(temp, '\n');
	if (newline)
	{
		*newline = '\0';
		line = ft_strjoin(temp, "\n");
		free(stash);
		stash = ft_strjoin(newline + 1, NULL);
		free(temp);
		return (line);
	}
	res = read_next_line(fd, &stash);
	if (res > 0)
		return (get_next_line(fd));
	return (NULL);
}
