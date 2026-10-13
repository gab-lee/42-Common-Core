/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/13 22:16:13 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(const int fd)
{
	static t_node	*fd_nodes;
	t_node			*temp;
	char			*line;

	if (fd < 0)
		return (NULL);
	temp = find_file_safe(fd, fd_nodes);
	read_until_newline (&temp);
	line = make_line(&temp);
	ft_lstclear(&temp, del);
	return (line);
}

t_node	*find_file_safe(const int fd, t_node **fd_nodes)
{
	t_node	*cur;
	t_node	*new_node;

	if (!fd_nodes || !*fd_nodes)
	{
		new_node = create_node (fd, NULL);
		*fd_nodes = new_node;
		return (new_node);
	}
	cur = *fd_nodes;
	while (cur->next)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	if (cur->fd == fd)
		return (cur);
	else
	{
		new_node = create_node (fd, NULL);
		cur->next = new_node;
		return (new_node);
	}
}
int	read_until_newline(t_node **temp)
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

char	*make_line(t_node **file_node)
{
	char *line;

	*line = make_empty_line(*file_node);
	if (!line)
		return (NULL);
	(void)file_node;
	return (line);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	
}