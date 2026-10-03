/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/03 18:35:37 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_from_stash(int fd, char **line, char **stash)
{
	int	i;
	int	j;
	int	new_line_reached;

	i = -1;
	j = 0;
	new_line_reached = 0;
	while (++i, *stash[i])
	{
		if (*stash[i] == '\n' && !new_line_reached)
			new_line_reached = 1;
		if (new_line_reached)
		{
			*stash[j] = *stash[i];
			j++;
		}
		else
			line[i] = stash[i];
	}
	if (new_line_reached)
		*stash[j] = '\0';
	else
		return (read_next_line(fd, line, stash));
	return (1);
}

int	read_next_line(const int fd, char **line, char **stash)
{
	int		res;
	char	*buffer;

	buffer = malloc((BUFF_SIZE + 1) * sizeof(char));
	buffer[BUFF_SIZE] = '\0';
	res = read(fd, buffer, BUFF_SIZE);
	if (res == 0 || res == -1)
	{
		free(buffer);
		return (res);
	}
	if (ft_strchr(buffer, '\n'))
	{
		*ft_strchr(buffer, '\n') = '\0';
		*line = ft_strjoin(*line, buffer);
		*stash = ft_strjoin("", ft_strchr(buffer, '\n') + 1);
		free(buffer);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, buffer);
		free(buffer);
		return (read_next_line(fd, line, stash));
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = NULL;
	while (++i, str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			ptr = (char *)&str[i];
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = -1;
	while (len++, str[len])
		;
	return (len);
}