/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:11:58 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 23:31:39 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*alloc_line(t_node **file, int *len, int res)
{
	char	*line;
	t_node	*cur;

	cur = *file;
	*len = 0;
	if (res < 0)
		return (NULL);
	while (cur->next_buffer)
	{
		*len += ft_strlen_safe(cur->str);
		cur = cur ->next_buffer;
	}
	if (res == 0)
		*len += ft_strlen_safe(cur->str);
	else
		*len += (unsigned int)(ft_strchr_safe(cur->str, '\n') - cur->str) + 1;
	line = malloc((*len +1) * sizeof(char));
	if (!line)
		return (NULL);
	line[*len] = '\0';
	return (line);
}

t_node	*new_node(const int fd, char *str)
{
	t_node	*node;
	int		len;
	int		i;

	i = -1;
	node = malloc(1 * sizeof(t_node));
	if (!node)
		return (NULL);
	node->fd = fd;
	len = ft_strchr_safe(str);
	node->str = malloc((len +1) * sizeof(char));
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	while (++i, str[i])
		node->str[i] = str[i];
	node->str[i] = '\0';
	node->next_file = NULL;
	node->next_buffer = NULL;
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
