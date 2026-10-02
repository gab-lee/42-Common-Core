*This project has been created as part of the 42 curriculum by gabrlee.*

# get_next_line

## Description

get_next_line is a function that reads a file descriptor and returns one line per call, so a loop of calls walks through a file (or standard input) line by line.

```c
char	*get_next_line(int fd);
```

- returns the line that was read, including the terminating `\n` (unless the file ends without one)
- returns `NULL` when there is nothing left to read or an error occurred
- only `read`, `malloc` and `free` are allowed, libft and global variables are not

## Instructions

### compile

`get_next_line` has no Makefile, compile it together with your own `main.c`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` sets how many bytes each `read()` call asks for. it can be changed at compile time (try `1`, `9999`, `10000000`) and the project also compiles without the `-D` flag, using the default set in `get_next_line.h`.

### use it

```c
#include "get_next_line.h"

int	fd = open("file.txt", O_RDONLY);
char	*line;

while ((line = get_next_line(fd)) != NULL)
{
	printf("%s", line);
	free(line);
}
close(fd);
```

every returned line is malloc'd, the caller has to free it.

## Algorithm

<!-- TODO (required by the subject): explain and justify your algorithm in your own words. -->
<!-- things an evaluator will expect this section to answer: -->
<!-- - what the static variable stores between calls, and why it has to be static -->
<!-- - what happens on each call, from read() to the returned line -->
<!-- - what is left in the static variable after a line is returned -->
<!-- - how EOF, a missing final \n, and read() errors are handled -->
<!-- - why this approach reads as little as possible instead of the whole file -->
<!-- - who frees what, and when -->

## Resources

- [read(2) man page](https://man7.org/linux/man-pages/man2/read.2.html), how `read()` returns bytes, `0` at EOF and `-1` on error
- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to
- [file descriptors](https://man7.org/linux/man-pages/man2/open.2.html), what an fd is and how `open()` returns one

### AI usage

used Claude (Claude Code) for:
- reading the subject PDF and listing where my first draft did not match the current subject (prototype, libft ban, `BUFFER_SIZE` naming, files to submit)
- discussing the structure of the project through questions, not code
- drafting the skeleton of this README

no function implementation was written or fixed by AI, all the `.c` logic is mine.
