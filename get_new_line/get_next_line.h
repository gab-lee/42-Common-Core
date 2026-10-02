/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:23:31 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/02 13:23:34 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <stdio.h>
char	*get_next_line(const int fd);
int read_next_line(const int fd, char **line, char **stash);
int read_from_stash(int fd, char **line, char **stash);

#define FALSE 0
#define TRUE 1
#define BUFF_SIZE 1
#endif
