/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 11:57:54 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(const int fd)
{
	static t_node	*fd_nodes;
	t_node			*temp;
	char			*line;
	int				res;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	temp = find_file_safe(fd, &fd_nodes);
	res = read_until_newline (&temp);
	line = make_line(&temp, res);
	clear_used_nodes(&temp, res);
	return (line);
}

t_node	*find_file_safe(const int fd, t_node **fd_nodes)
{
	t_node	*cur;
	t_node	*new_node;

	if (!fd_nodes || !*fd_nodes)
	{
		new_node = create_node_safe (fd, NULL);
		*fd_nodes = new_node;
		return (new_node);
	}
	cur = *fd_nodes;
	while (cur->next_fd)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next_fd;
	}
	if (cur->fd == fd)
		return (cur);
	else
	{
		new_node = create_node_safe (fd, NULL);
		cur->next_fd = new_node;
		return (new_node);
	}
}

int	read_until_newline(t_node **fd_node)
{
	int		res;
	char	*buffer;
	t_node	*cur;
	t_node	*new_node;

	cur = *fd_node;
	if (!cur)
		return (-1);
	while (cur->next)
		cur = cur->next;
	while (!ft_strchr_safe(cur->line, '\n'))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			res = -1;
		res = read(cur->fd, buffer, BUFFER_SIZE);
		if (res == -1 || res == 0)
		{
			free(buffer);
			return (res);
		}
		buffer[res] = '\0';
		new_node = create_node_safe(cur->fd, buffer);
		free(buffer);
		if (!new_node)
			return (-1);
		cur->next = new_node;
		cur = cur->next;
	}
	return (1);
}

char	*make_line(t_node **file_node, int res)
{
	char	*line;
	t_node	*cur;
	t_node	*new_node;
	int		i;
	int		j;
	int		len;

	cur = *file_node;
	j = 0;
	line = make_empty_line(file_node, &len, res);
	if (!line || !len)
	{
		free(line);
		return (NULL);
	}
	while (j < len)
	{
		i = -1;
		while (++i, j < len && cur->line[i])
			line[j++] = cur->line[i];
		if (j < len)
			cur = cur->next;
	}
	new_node = create_node_safe(cur->fd, &(cur->line[i]));
	cur->next = new_node;
	return (line);
}

void	clear_used_nodes(t_node **fd_node, int res)
{
	t_node	*temp;
	t_node	*cur;

	if (!*fd_node || !(*fd_node)->next)
		return ;
	cur = *fd_node;
	while (cur->next)
	{
		temp = cur->next;
		free(cur->line);
		free(cur);
		cur = temp;
	}
	if (res == 0)
	{
		free(cur->line);
		free(cur);
		return ;
	}
	free((*fd_node)->line);
	(*fd_node)->line = cur->line;
}
