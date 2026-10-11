#include "libft.h"
#include "stdio.h"

void *memove(void *dest, const void *src, size_t n);

int main(void)
{
	char s1[] = "hello";
	char s2[] = "world";
	size_t i = 3;

	printf("str: %s", (unsigned char *) memove((void *)s1, (const void *)s2, i));
	return (0);	
}


void *memove(void *dest, const void *src, size_t n)
{
	unsigned char* d;
	const unsigned char* s;
	size_t i;

	i = -1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d>s)
	{
		while (++i, i<n)	
			d[n-i-1] = s[n-i-1];
	}
	else 
	{
		while (++i, i <n)
			d[i] = s[i];
	}
	return (dest);
}


