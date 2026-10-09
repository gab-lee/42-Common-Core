/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:31 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/08 22:36:19 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(const int fd);
int		read_from_stash(int fd, char **line, char **stash);
int		read_next_line(const int fd, char **line, char **stash);
char	*ft_gnl_strjoin_andfree(char *s1, char *s2, char **free_str);
char	*ft_gnl_strchr(const char *str, int c);
size_t	ft_gnl_strlen(const char *str);

#endif
