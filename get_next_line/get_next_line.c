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

	temp = ft_strjoin_safe_and_free(stash, NULL, NULL, NULL);
	newline = ft_strchr_safe(temp, '\n');
	if (newline)
	{
		*newline = '\0';
		line = ft_strjoin_safe_and_free(temp, "\n", &stash, NULL);
		stash = ft_strjoin_safe_and_free(newline + 1, NULL, &temp, NULL);
		return (line);
	}
	res = read_next_line(fd, &stash);
	if (res > 0)
	{
		free_all(&temp, &line, NULL);
		return (get_next_line(fd));
	}
	if (res == 0 && stash && *stash)
		return (ft_strjoin_safe_and_free(stash, "", &stash, &temp));
	free_all(&temp, &line, &stash);
	return (NULL);
}
