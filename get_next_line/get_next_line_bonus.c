/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 23:57:47 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(const int fd)
{
	static t_node	*file_lst;
	t_node			*file;
	t_node			*prev;
	char			*line;
	int				res;

	prev = NULL;
	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	file = get_file_safe(fd, &file_lst, &prev);
	if (!file)
		return (NULL);
	res = read_and_create_safe (&file);
	line = build_line(&file, res);
	if (!line)
		res = -1;
	keep_leftover(&file_lst, &file, res, &prev);
	return (line);
}

t_node	*get_file_safe(const int fd, t_node **file_lst, t_node **prev)
{
	t_node	*cur;
	t_node	*node;

	if (!file_lst || !*file_lst)
	{
		node = new_node (fd, NULL);
		*file_lst = node;
		return (node);
	}
	cur = *file_lst;
	while (cur->next_file)
	{
		if (cur->fd == fd)
			return (cur);
		*prev = cur;
		cur = cur->next_file;
	}
	if (cur->fd == fd)
		return (cur);
	node = new_node (fd, NULL);
	cur->next_file = node;
	*prev = cur;
	return (node);
}

int	read_and_create_safe(t_node **file)
{
	int		res;
	char	*buffer;
	t_node	*cur;

	cur = *file;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	while (!ft_strchr_safe(cur->str, '\n'))
	{
		res = read(cur->fd, buffer, BUFFER_SIZE);
		if (res <= 0)
			break ;
		buffer[res] = '\0';
		cur->next_buffer = new_node(cur->fd, buffer);
		if (!(cur->next_buffer))
			return (-1);
		cur = cur->next_buffer;
		res = 1;
	}
	free(buffer);
	return (res);
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

void	keep_leftover(t_node **file_lst, t_node **file, int res, t_node **prev)
{
	t_node	*last;
	t_node	*temp;

	if (!file || !*file)
		return ;
	last = (*file)->next_buffer;
	while (last && last->next_buffer)
	{
		temp = last->next_buffer;
		free(last->str);
		free(last);
		last = temp;
	}
	free((*file)->str);
	(*file)->str = NULL;
	(*file)->next_buffer = NULL;
	if (res == 1 && last && last->str[0])
		(*file)->str = last->str;
	else if (last)
		free(last->str);
	free(last);
}
