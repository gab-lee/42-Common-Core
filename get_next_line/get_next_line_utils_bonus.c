/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:21:51 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/08 22:36:19 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_from_stash(int fd, char **line, char **stash)
{
	char	*temp;

	temp = ft_gnl_strjoin_andfree("", *stash);
	free(*stash);
	if (ft_gnl_strchr(temp, '\n'))
	{
		*stash = ft_gnl_strjoin_andfree("", ft_gnl_strchr(temp, '\n') + 1);
		*ft_gnl_strchr(temp, '\n') = '\0';
		*line = ft_gnl_strjoin_andfree("", temp);
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_gnl_strjoin_andfree("", temp);
		free(temp);
		return (read_next_line(fd, line, stash));
	}
}

int	read_next_line(const int fd, char **line, char **stash)
{
	int		res;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	res = read(fd, buffer, BUFFER_SIZE);
	if (res == 0 || res == -1)
	{
		free(buffer);
		return (res);
	}
	if (ft_gnl_strchr(buffer, '\n'))
	{
		*stash = ft_gnl_strjoin_andfree("", ft_gnl_strchr(buffer, '\n') + 1);
		*ft_gnl_strchr(buffer, '\n') = '\0';
		*line = ft_gnl_strjoin_andfree(*line, buffer);
		free(buffer);
		return (1);
	}
	else
	{
		*line = ft_gnl_strjoin_andfree(*line, buffer);
		free(buffer);
		return (read_next_line(fd, line, stash));
	}
}

char	*ft_gnl_strjoin_andfree(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

char	*ft_gnl_strchr(const char *str, int c)
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

size_t	ft_gnl_strlen(const char *str)
{
	int	len;

	len = -1;
	while (len++, str[len])
		;
	return (len);
}