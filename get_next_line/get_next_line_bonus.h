/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:31 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 11:09:27 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef	struct	s_node
{
	int				fd;
	char			*line;
	struct s_node	*next_fd;
	struct s_node	*next;
}	t_node;

char	*get_next_line(const int fd);
t_node	*find_file_safe(const int fd, t_node **fd_nodes);
int		read_until_newline(t_node **fd_node);
char	*make_line(t_node **file_node);
void	clear_used_nodes(t_node **fd_node,int res);
char	*make_empty_line(t_node **file_node, int *len);
t_node	*create_node(const int fd, char *line);
char	*ft_strchr_safe(const char *str, int c);
int		ft_strlen_safe(char *str);
char	*ft_strjoin_safe(char *s1, char *s2);


#endif
