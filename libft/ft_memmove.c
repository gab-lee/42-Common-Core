#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
  size_t i;
  void *tmp;

  i = -1;
  tmp = malloc(n * sizeof(void *));
  while (++i, i < n)
    *((unsigned char *)tmp + i) = *((unsigned char *)src + i);
  i = -1;
  while (++i, i < n)
    *((unsigned char *)dest + i) = *((unsigned char *)tmp + i);
  return (dest);
}