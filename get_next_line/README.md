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

the bonus (multiple file descriptors) uses a linked list method.

each node contains:

| field | holds |
|---|---|
| `fd` | the file descriptor the node belongs to |
| `line` | the buffer from one `read()` call, null terminated |
| `next_fd` | the next file node, every node inherits it from the previous node |
| `next` | the next node with the same `fd` |

`stash` does not hold a line. it holds the starting node for all nodes.

```
stash
  |
  v
[fd 3] --next_fd--> [fd 4] --next_fd--> NULL
  |                   |
 next                next
  |                   |
  v                   v
[fd 3] -> fd 4      [fd 4] -> NULL
  |                   |
 next                next
  |                   |
  v                   v
[fd 3] -> fd 4       NULL
  |
 next
  |
  v
 NULL
```

down is `next` (same fd). right is `next_fd` (next file). `-> fd 4` is a node's inherited `next_fd`.

```
get_next_line(fd)
|
+-- find_file(stash, fd)
|   +-- stash empty?            --> create file node, stash = file node
|   +-- file node for fd found? --> return file node
|   +-- not found               --> create file node, link with next_fd, return it
|
+-- read_until_newline(file node)
|   |
|   +-- last node contains '\n'? --> return 1
|   +-- create node, next_fd = previous node->next_fd
|   +-- read(fd, buffer, BUFFER_SIZE - 1), append '\0'
|   |   +-- -1 (error) --> return -1
|   |   +-- 0  (EOF)   --> return 0
|   +-- '\n' in new node?
|       +-- yes --> return 1
|       +-- no  --> create node and read again
|
|   each read asks for BUFFER_SIZE - 1 bytes, so a node's line
|   (bytes + '\0') fits in BUFFER_SIZE
|
+-- make_empty_line(file node)
|   |
|   +-- len = len of line in first node
|   |       + (middle nodes * (BUFFER_SIZE - 1))
|   |       + len of line in last node up to and including '\n'
|   |       + 1 for '\0'
|   +-- return malloc(len)
|
+-- fill_line_safe(file node, line)
    |
    +-- iterate through nodes, copy each node's line into line
    +-- last node: copy up to and including '\n'
    +-- file node->line = last node's line after '\n'
    |   (NULL if nothing is left after '\n')
    +-- clear all nodes after the file node
    +-- return line
```

## Resources

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
