/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_stash.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:31 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/11 10:20:34 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_STASH_H
# define GET_NEXT_LINE_STASH_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(const int fd);
char	*extract_line(char **stash, char **temp, char *newline);
void	free_all(char **s1, char **s2, char **s3);
int		read_next_line(const int fd, char **stash);
char	*ft_strjoin_safe_and_free(char *s1, char *s2, char **fs1, char **fs2);
char	*ft_strchr_safe(const char *str, int c);
size_t	ft_strlen_safe(const char *str);

#endif
