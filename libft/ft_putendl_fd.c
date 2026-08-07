#include "libft.h"

void ft_putendl_fd(char *str, int fd)
{
    int i;

    i = -1;
    while (++i, str[i])
        write(fd, &str[i], 1);
    write(fd, "\n", 1);
}