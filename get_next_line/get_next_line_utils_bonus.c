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

#include "get_next_line_bonus.h"

t_node	*find_file(const int fd, t_node **fd_nodes)
{
	t_node	*cur;
	t_node	*new_node;

	cur = *fd_nodes;
	while (cur->next)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	new_node = create_node (fd, NULL);
	cur->next = new_node;
	return (new_node);
}

int	grow_node_till_valid_or_end(t_node **temp)
{
	int		newline;
	int		res;
	char	*buffer;
	t_node	*cur;
	t_node	*new_node;

	newline = 0;
	cur = *temp;
	while (cur->next)
		cur = cur->next;
	if (ft_strchr_safe(cur->line, '\n'))
		return (1);
	while (!newline)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1 || res == 0)
			return (res);
		new_node = create_node(fd, buffer);
		cur->next = new_node;
		if (ft_strchr_safe(new_node->line, '\n'))
			newline = 1;
		cur = cur->next;
	}
	return (res);
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	
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
