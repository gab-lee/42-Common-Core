#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
    int i;
    static char *stash;

    if (stash)
        i = read_from_stash(fd, line, &stash);
    else
        i = read_next_line(fd, line, &stash);
    return (i);
}

int read_next_line(const int fd, char **line, char **stash)
{
    int i;
    char *buffer;

    printf("reading next line");
    buffer = malloc((BUFF_SIZE + 1) * sizeof(char));
    buffer[BUFF_SIZE] = '\0';
    i = read(fd, buffer, BUFF_SIZE);
    if (i == 0 || i == -1)
    {
        free(buffer);
        return (i);
    }
    else if (ft_strchr(buffer, '\n'))
    {
        ft_strlcpy((char *)(ft_strchr(buffer, '\n') + 1), *stash, ft_strlen((char *)(ft_strchr(buffer, '\n') + 1)));
        free(buffer);
        return (1);
    }
    else
    {
        *line = ft_strjoin(*line, buffer);
        free(buffer);
        return (read_next_line(fd, line, stash));
    }
}
int read_from_stash(int fd, char **line, char **stash)
{
    if (ft_strchr(*stash, '\n'))
        ft_strlcpy(*line, *stash, ft_strlen(*stash));
    else
        read_next_line(fd, line, stash);
    return (1);
}