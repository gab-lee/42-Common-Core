#include "libft.h"

void ft_putcharfd(char c, int fd)
{
    write(fd, &c, 1);
}