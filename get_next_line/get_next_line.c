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
	char		*temp;
	char		*newline;
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strjoin_safe_and_free(stash, NULL, NULL, NULL);
	newline = ft_strchr_safe(temp, '\n');
	if (newline)
		return (extract_line(&stash, &temp, newline));
	res = read_next_line(fd, &stash);
	if (res > 0)
	{
		free_all(&temp, NULL, NULL);
		return (get_next_line(fd));
	}
	if (res == 0 && stash && *stash)
		return (ft_strjoin_safe_and_free(stash, "", &stash, &temp));
	free_all(&temp, NULL, &stash);
	return (NULL);
}

char	*extract_line(char **stash, char **temp, char *newline)
{
	char	*line;

	*newline = '\0';
	line = ft_strjoin_safe_and_free(*temp, "\n", stash, NULL);
	*stash = ft_strjoin_safe_and_free(newline + 1, NULL, temp, NULL);
	return (line);
}
