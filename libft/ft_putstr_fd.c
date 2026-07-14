include "libft.h"
void ft_putstrfd(char *str, int fd)
{
    while(*(str++))
	  	write(fd, *str, 1);
}