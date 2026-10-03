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

overview: GNL returns next line, however, due to undefined buffer, what is read might be more than 1 line. Excess will be stored within stash. A static variable that will maintain memory in between calls. 

Stash is a static, static is by default NULL and no need to initialise. 

1. If Stash exists helper f(Read_from_stash) read from stash is triggered, elese ::fread next buff:: is triggered. 

Read from stash
3. iterate stash, writing line,
4. If char is \n break and write stash
5. if not read_next_buffer

Read next buffer
6. Read next buffer. If 0 -> EOF return NULL, if -1 error, return NULL
7. Use strchr to check if if \n exist within buffer if it does

if \n exist
8. Change \n to null terminator (required also for strjoin to work), and only add before returning
9. line = strjoin current line and line up till strchr (it is a pointer)
10. Stash is simply strjoin starting from strchr + 1 (move it pass new character)
11. Return 1 no issuess

if \n does not exist 
11. line = strjoin line + buffer (simpler), don't change stash. 
12. return get tnext line

Strjoin is used over strlcpy/strdup because it can be used to grow line as well as to implement stash and it does malloc so that's great.

Read next line

bonus

## Resources

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
