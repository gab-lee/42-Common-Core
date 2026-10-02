*This project has been created as part of the 42 curriculum by gabrlee.*

# get_next_line

## Description

get_next_line is a function that reads a file descriptor and returns one line per call, so a loop of calls walks through a file (or standard input) line by line.

```c
char	*get_next_line(int fd);
```

| case | argument | return |
|---|---|---|
| 1. line read | `fd` | the line that was read, including the `\n` (unless the file ends without one) |
| 2. nothing left to read (EOF) | `fd` | `NULL` |
| 3. error occurred | `fd` | `NULL` |

| | functions |
|---|---|
| allowed | `read`, `malloc`, `free` |
| forbidden | libft, `lseek`, global variables |

## Instructions

### compile

```bash
make                    # builds get_next_line.a with the default BUFFER_SIZE
make BUFFER_SIZE=42     # builds with a custom BUFFER_SIZE
make clean              # removes object files
make fclean             # removes object files + get_next_line.a
make re                 # fclean + rebuild
```

then link it with your own `main.c`:

```bash
cc -Wall -Wextra -Werror main.c get_next_line.a
```

`BUFFER_SIZE` sets how many bytes each `read()` call asks for. try `1`, `9999` and `10000000`. without it, the default set in `get_next_line.h` is used.

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

## Helper functions

all helpers live in `get_next_line_utils.c`.

| function | description |
|---|---|
| | |

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

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
