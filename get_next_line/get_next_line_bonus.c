/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/13 23:12:31 by gabrlee          ###   ########.fr       */
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
	temp = find_file_safe(fd, &fd_nodes);
	res = read_until_newline (&temp);
	if (res < 0)
		return (NULL);
	//what if res == 0?
	line = make_line(&temp);
	clear_used_nodes(&temp, res);
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

int	read_until_newline(t_node **fd_node)
{
	int		res;
	char	*buffer;
	t_node	*cur;
	t_node	*new_node;

	cur = *fd_node;
	while (cur->next)
		cur = cur->next;
	while (!ft_strchr_safe(cur->line, '\n'))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		res = read(cur->fd, buffer, BUFFER_SIZE);
		if (res == -1 || res == 0)
			return (res);
		buffer[res] = '\0';
		new_node = create_node(cur->fd, buffer);
		free(buffer);
		cur->next = new_node;
		cur = cur->next;
	}
	return (1);
}

char	*make_line(t_node **file_node)
{
	char	*line;
	t_node	*cur;
	t_node	*new_node;
	int		i;
	int		j;

	cur = *file_node;
	line = make_empty_line(file_node);
	if (!line)
		return (NULL);
	j = 0;
	while (cur && cur->line)
	{
		i = -1;
		while (++i, cur->line[i] && line[i])
		{
			line[j++] = cur->line[i];
			if (cur->line[i] == '\n')
			{
				new_node = create_node(cur->fd, &(cur->line[i + 1]));
				cur->next = new_node;
				break ;
			}
		}
		cur = cur->next;
	}
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
