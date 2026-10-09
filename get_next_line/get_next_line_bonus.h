/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:21:29 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/08 22:10:42 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(const int fd);
int		read_from_stash(int fd, char **line, char **stash);
int		read_next_line(const int fd, char **line, char **stash);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strchr(const char *str, int c);
size_t	ft_gnl_strlen(const char *str);

//# define BUFFER_SIZE 42

#endif
