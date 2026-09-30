#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <stdio.h>
int get_next_line(const int fd, char **line);
int read_next_line(const int fd, char **line, char **stash);
int read_from_stash(int fd, char **line, char **stash);

#define FALSE 0
#define TRUE 1
#define BUFF_SIZE 1
#endif
