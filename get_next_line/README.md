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

`read()` pulls `BUFFER_SIZE` bytes at a time, so one read can return more than one line. the excess is kept in `stash`, a `static char *` that survives between calls. a static starts as `NULL`, so it needs no initialisation.

```
get_next_line(fd)
|
+-- stash exists?
|   |
|   +-- yes --> read_from_stash
|   |           |
|   |           +-- walk stash, copying chars into line
|   |           |
|   |           +-- '\n' found?
|   |               +-- yes --> keep what is after '\n' in stash --> return 1
|   |               +-- no  --> read_next_buffer
|   |
|   +-- no  --> read_next_buffer
|
+-- read_next_buffer
|   |
|   +-- read(fd, buffer, BUFFER_SIZE)
|   |   +-- 0  (EOF)   --> return NULL
|   |   +-- -1 (error) --> return NULL
|   |
|   +-- strchr(buffer, '\n')?
|       |
|       +-- yes --> replace '\n' with '\0'
|       |           line  = strjoin(line, buffer)
|       |           stash = strjoin("", newline_ptr + 1)
|       |           return 1
|       |
|       +-- no  --> line = strjoin(line, buffer)
|                   stash unchanged
|                   read_next_buffer again
|
+-- add '\n' back to line --> return line
```

| state | what lives where |
|---|---|
| line | everything up to (not including) the `\n` |
| stash | everything after the `\n`, kept for the next call |
| buffer | freed after every read |

`strjoin` is used over `strlcpy`/`strdup` because it both grows `line` and builds `stash`, and it allocates the result. However, because strjoin includes malloc, I need to free s1 & s2 after it. 
- Solved for read from stash by creating a temp variable.
- Not yet done for read next line. 

### bonus

## Resources

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
