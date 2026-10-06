/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/06 23:09:34 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_from_stash(int fd, char **line, char **stash)
{
	char	*temp;

	temp = ft_strjoin("", *stash);
	free(*stash);
	if (ft_strchr(temp, '\n'))
	{
		*stash = ft_strjoin("", ft_strchr(temp, '\n') + 1);
		*ft_strchr(temp, '\n') = '\0';
		*line = ft_strjoin("", temp);
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_strjoin("", temp);
		free(temp);
		free(*stash);
		return (read_next_line(fd, line, stash));
	}
}

int	read_next_line(const int fd, char **line, char **stash)
{
	int		res;
	char	*buffer;
	char	*temp;

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
		*stash = ft_strjoin("", ft_strchr(buffer, '\n') + 1);
		*ft_strchr(buffer, '\n') = '\0';
		if (*line)
		{
			temp = ft_strjoin("", *line);
			free(*line);
			*line = ft_strjoin(temp, buffer);
		}
		else
			*line = ft_strjoin("", buffer);
		free(buffer);
		return (1);
	}
	else
	{
		temp = ft_strjoin("", *line);
		free(*line);
		*line = ft_strjoin(temp, buffer);
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