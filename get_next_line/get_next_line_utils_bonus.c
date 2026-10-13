/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/13 23:16:05 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*make_empty_line(t_node **file_node)
{
	char	*line;
	int		len;
	t_node	*cur;

	cur = *file_node;
	len = 0;
	while (cur)
	{
		len += strlen_safe(cur->line);
		cur = cur ->next;
	}
	line = malloc((len +1 ) * sizeof(char));
	if (!line)
		return (NULL);
	line[len + 1] = '\0';
	return (line);
}

t_node *create_node(const int fd, char *line)
{
	t_node	*node;

	node = malloc(1 * sizeof(t_node));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->line = line;
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

int	strlen_safe(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = -1;
	while (++len, str[len])
		len++;
	return (len);
}
