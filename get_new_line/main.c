#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("./test.txt", O_RDONLY);
    printf("%d", fd);
    while (get_next_line(fd, &line))
        printf("New line: %s\n", line);
    close(fd);
}
