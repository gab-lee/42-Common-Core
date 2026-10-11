/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/11 10:27:24 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_next_line(const int fd, char **stash)
{
	int		res;
	char	*buffer;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	res = read(fd, buffer, BUFFER_SIZE);
	if (res == 0 || res == -1)
	{
		free(buffer);
		return (res);
	}
	temp = ft_strjoin_safe(*stash, NULL);
	free(*stash);
	*stash = ft_strjoin_safe(temp, buffer);
	if (temp)
		free(temp);
	if (buffer)
		free(buffer);
	if (ft_strchr_safe(*stash, '\n'))
		return (1);
	else
		return (read_next_line(fd, stash));
}

char	*ft_strjoin_safe(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	str = malloc((ft_strlen_safe(s1) + ft_strlen_safe(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_safe(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (++i, str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)&str[i]);
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen_safe(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = -1;
	while (len++, str[len])
		;
	return (len);
}
