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

`read()` pulls `BUFFER_SIZE` bytes at a time, so one read can return more than one line. there is no separate `line` buffer that grows across reads. everything read is stored in `stash`, a `static char *` that survives between calls, so all allocated memory sits in one place for memory checks. a static starts as `NULL`, so it needs no initialisation.

```
get_next_line(fd)
|
+-- stash contains '\n'?
|   +-- yes --> extract_line
|   +-- no  --> read_next_buffer
|
+-- read_next_buffer
|   |
|   +-- read(fd, buffer, BUFFER_SIZE)
|   |   +-- -1 (error) --> free stash, stash = NULL --> return NULL
|   |   +-- 0  (EOF)   --> stash empty?
|   |                      +-- yes --> free stash, stash = NULL --> return NULL
|   |                      +-- no  --> extract_line
|   |
|   +-- stash = strjoin(stash, buffer), free old stash
|   +-- '\n' in stash?
|       +-- yes --> extract_line
|       +-- no  --> read_next_buffer again
|
+-- extract_line
    |
    +-- copy stash up to and including '\n' into a new string --> returned line
    +-- keep what is after '\n' as the new stash, free old stash
    +-- return line
```

| state | what lives where |
|---|---|
| stash | every byte read and not yet returned |
| returned line | allocated only at the moment of return, freed by the caller |
| buffer | freed after every read |

`strjoin` appends each buffer to `stash` and allocates the result, so the old `stash` must be freed after every join.

### bonus

note: for the bonus (multiple file descriptors), I want to try using a linked list, with one node per `fd` holding that fd's `stash`.

## Resources

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
