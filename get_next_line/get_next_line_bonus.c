/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:26 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/11 10:27:50 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(const int fd)
{
	static t_node *fd_nodes;
	t_node temp;

	temp = find_file(fd)
	while (temp)
		cur = temp 
		if cur contains newline 
			return lines till cur node)
		else 
			check next node 
				if end 
					read next add new node BUFFER_SIZE
		temp = cur -> next_node;
	if (find_next_valid_node())
		return (lines till cur node)
}

/*
** find_next_valid_node (helper)
**
** res = read(fd, buffer, BUFFER_SIZE)
** if res == -1
**     do not add the node
**     return NULL
**     TODO: who frees the chunks already stored for this fd?
** if res == 0
**     if content is empty
**         remove the node
**     TODO: content not empty (last line has no '\n') -> ?
** else
**     create a new node with the buffer
**     if the new node has no newline
**         create another one (read again)
**     return get_next_line(fd)
**
** TODO: one return type only. It currently returns the read result,
**       0, NULL and get_next_line (a char *).
** TODO: the main loop also reads ("read next add new node").
**       Which one owns reading?
*/
