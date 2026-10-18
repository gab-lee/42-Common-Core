/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 11:10:10 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*make_empty_line(t_node **file_node, int *len)
{
	char	*line;
	t_node	*cur;

	cur = *file_node;
	*len = 0;
	while (cur->next)
	{
		*len += ft_strlen_safe(cur->line);
		cur = cur ->next;
	}
	len += (unsigned int)(ft_strchr_safe(cur->line, '\n') - cur->line) + 1;
	line = malloc((*len +1) * sizeof(char));
	if (!line)
		return (NULL);
	line[*len] = '\0';
	return (line);
}

t_node	*create_node(const int fd, char *line)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->line = ft_strjoin_safe("", line);
	node->next_fd = NULL;
	node->next = NULL;
	return (node);
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

int	ft_strlen_safe(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = -1;
	while (++len, str[len])
		;
	return (len);
}

char	*ft_strjoin_safe(char *s1, char *s2)
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