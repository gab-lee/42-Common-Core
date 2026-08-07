#include "libft.h"

void *ft_memset(void *ptr, int c, size_t n)
{
  size_t i;

  i = -1;
  while (++i, i < n)
    *((unsigned char *)ptr + i) = (char)(c);
  return (ptr);
}
