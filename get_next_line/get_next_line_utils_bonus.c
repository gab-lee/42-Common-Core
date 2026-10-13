/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/13 22:06:45 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*make_empty_line(t_node *file_node)
{
	char	*line;
	int		len;

	(void)file_node;
	len = 0;
	line = malloc(len * sizeof(char));
	if (!line)
		return (NULL);
	return (line);
}



t_node *create_node(const int fd, char *line)
{
	t_node *node;

	node = (1 * sizeof(t_node));
	if (!new_node)
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

char *return_line(t_node **node)
{
	t_node	*cur;
	char	*line;
	int		len;

	cur = *node;
	len = 0;
	while (cur->next)
		len += strlen(cur->line);
	line = malloc(len * sizeof(char));
	if (!len || !line)
		return (NULL);
	cur = *node;
	while (++i, cur->next)
	{
		while (++j, cur->line[j])
			line[len] = cur->line[j];
		j = 0;
		cur = cur->next;
	}
	return (line);
}


