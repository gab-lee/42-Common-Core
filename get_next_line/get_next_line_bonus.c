/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 23:04:16 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(const int fd)
{
	static t_node	*files;
	t_node			*file;
	t_node			*prev;
	char			*line;
	int				res;

	prev = NULL;
	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	file = get_file_safe(fd, &files, &prev);
	res = read_and_create_safe (&file);
	line = build_line(&file, res);
	if (keep_leftover(&file, res, &prev))
		return (line);
	else
	{
		keep_leftover(&file, -1, &prev);
		return (NULL);
	}
}

t_node	*get_file_safe(const int fd, t_node **files, t_node **prev)
{
	t_node	*cur;
	t_node	*node;

	if (!files || !*files)
	{
		node = new_node (fd, NULL);
		*files = node;
		return (node);
	}
	cur = *files;
	while (cur->next_file)
	{
		if (cur->fd == fd)
			return (cur);
		*prev = cur;
		cur = cur->next_file;
	}
	if (cur->fd == fd)
		return (cur);
	else
	{
		node = new_node (fd, NULL);
		cur->next_file = node;
		*prev = cur;
		return (node);
	}
}

int	read_and_create_safe(t_node **file)
{
	int		res;
	char	*buffer;
	t_node	*cur;
	t_node	*node;

	cur = *file;
	if (!cur)
		return (-1);
	while (cur->next_buffer)
		cur = cur->next_buffer;
	while (!ft_strchr_safe(cur->str, '\n'))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (-1);
		res = read(cur->fd, buffer, BUFFER_SIZE);
		if (res == -1 || res == 0)
		{
			free(buffer);
			return (res);
		}
		buffer[res] = '\0';
		node = new_node(cur->fd, buffer);
		free(buffer);
		if (!node)
			return (-1);
		cur->next_buffer = node;
		cur = cur->next_buffer;
	}
	return (1);
}

char	*build_line(t_node **file, int res)
{
	char	*line;
	t_node	*cur;
	int		i;
	int		j;
	int		len;

	cur = *file;
	i = 0;
	j = 0;
	line = alloc_line(file, &len, res);
	while (line && j < len)
	{
		i = 0;
		while (j < len && cur->str[i])
			line[j++] = cur->str[i++];
		if (j < len)
			cur = cur->next_buffer;
	}
	if (line && len)
		cur->next_buffer = new_node(cur->fd, &(cur->str[i]));
	if (line && len && cur->next_buffer)
		return (line);
	free(line);
	return (NULL);
}

int	keep_leftover(t_node **file, int res, t_node **prev)
{
	t_node	*temp;
	t_node	*cur;

	if (!file || !*file)
		return (1);
	cur = (*file)->next_buffer;
	while (cur && cur->next_buffer)
	{
		temp = cur->next_buffer;
		free(cur->str);
		free(cur);
		cur = temp;
	}
	free((*file)->str);
	if (res == 1 || (res == 0 && cur && cur->str))
	{
		(*file)->str = ft_strjoin_safe("", cur->str);
		free(cur->str);
		if (!(*file)->str)
			return (0);	
	}
	if (res == -1 || (res == 0 && (!cur || !(cur->str))))
		(*prev)->next_file = (*file)->next_file;
	free(cur);
	free(*file);
	return (1);
}

