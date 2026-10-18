/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:31 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/18 22:37:20 by gabrlee          ###   ########.fr       */
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
	char			*str;
	struct s_node	*next_file;
	struct s_node	*next_buffer;
}	t_node;

char	*get_next_line(const int fd);
t_node	*get_file_safe(const int fd, t_node **files, t_node **prev);
int		read_and_create_safe(t_node **file);
char	*build_line(t_node **file, int res);
int	keep_leftover(t_node **file,int res, t_node **prev);
char	*alloc_line(t_node **file, int *len, int res);
t_node	*new_node(const int fd, char *str);
char	*ft_strchr_safe(const char *str, int c);
int		ft_strlen_safe(char *str);
char	*ft_strjoin_safe(char *s1, char *s2);


#endif
