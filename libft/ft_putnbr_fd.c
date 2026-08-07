#include "libft.h"

static void ft_putnbr_long_fd(long n, int fd);

void ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        write(fd, "-", 1);
        ft_putnbr_long_fd(-(long)n, fd);
    }
    else
        ft_putnbr_long_fd((long)n, fd);
}

static void ft_putnbr_long_fd(long n, int fd)
{
    char c;

    c = n % 10 + '0';
    if (n > 10)
        ft_putnbr_long_fd(n / 10, fd);
    write(fd, &c, 1);
}