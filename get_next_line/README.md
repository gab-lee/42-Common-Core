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
| `str` | the buffer from one `read()` call, null terminated |
| `next_file` | the next file node, every node inherits it from the previous node |
| `next_buffer` | the next node with the same `fd` |

`file_lst` does not hold a line. it holds the starting node for all nodes.

```
file_lst
  |
  v
[fd 3] --next_file--> [fd 4] --next_file--> NULL
  |                     |
 next_buffer           next_buffer
  |                     |
  v                     v
[fd 3] -> fd 4        [fd 4] -> NULL
  |                     |
 next_buffer           next_buffer
  |                     |
  v                     v
[fd 3] -> fd 4         NULL
  |
 next_buffer
  |
  v
 NULL
```

down is `next_buffer` (same fd). right is `next_file` (next file). `-> fd 4` is a node's inherited `next_file`.

```
get_next_line(fd)
|
+-- get_file_safe(file_lst, fd)
|   +-- file_lst empty?         --> create file node, file_lst = file node
|   +-- file node for fd found? --> return file node
|   +-- not found               --> create file node, link with next_file, return it
|
+-- read_and_create_safe(file node)
|   |
|   +-- last node contains '\n'? --> return 1
|   +-- create node, next_file = previous node->next_file
|   +-- read(fd, buffer, BUFFER_SIZE - 1), append '\0'
|   |   +-- -1 (error) --> return -1
|   |   +-- 0  (EOF)   --> return 0
|   +-- '\n' in new node?
|       +-- yes --> return 1
|       +-- no  --> create node and read again
|
|   each read asks for BUFFER_SIZE - 1 bytes, so a node's str
|   (bytes + '\0') fits in BUFFER_SIZE
|
+-- alloc_line(file node)
|   |
|   +-- len = len of str in first node
|   |       + (middle nodes * (BUFFER_SIZE - 1))
|   |       + len of str in last node up to and including '\n'
|   |       + 1 for '\0'
|   +-- return malloc(len)
|
+-- build_line(file node, line)
    |
    +-- iterate through nodes, copy each node's str into line
    +-- last node: copy up to and including '\n'
    +-- file node->str = last node's str after '\n'
    |   (NULL if nothing is left after '\n')
    +-- clear all nodes after the file node
    +-- return line
```

#### cleanup cases

`keep_leftover` runs at the end of every call. it ends in one of two outcomes: **keep** the file node holding a non-empty leftover, or **finish** the fd (free the file node and remove it from `file_lst`). `get_next_line` sets `res` to -1 before calling it when `build_line` returned `NULL`.

| `res` | chain at cleanup | example | returns | file node after |
|---|---|---|---|---|
| 1 | `F -> buffers... -> L("cd")` | `ab\ncd`, call 1 | the line | keep: `F("cd")` |
| 1 | `F("cd\nef") -> L("ef")` (no buffer nodes, F already held a `\n`) | `ab\ncd\nef` with a large buffer, call 2 | `"cd\n"` | keep: `F("ef")` |
| 1 | `F -> buffers... -> L("")` | `ab\n`, line ends exactly at the end of the read | the line | finish, recreated on the next call |
| 0 | `F -> buffers... -> L("")` | `abc`, call 1 | `"abc"` | finish |
| 0 | `F` alone | call after the last line, or empty file | `NULL` | finish |
| -1 | `F` alone, or `F -> buffers...` | `read` or `malloc` error, or `build_line` failed | `NULL` | finish |

`F` is the file node, buffer nodes are the nodes made by each `read()`, `L` (`last`) is the leftover node made by `build_line`.

```
keep_leftover(file_lst, file, res, prev)
|
+-- free every buffer node between F and last (str, then node)
+-- free F->str, F->str = NULL, F->next_buffer = NULL
|
+-- res == 1 and last exists and last->str is not empty?
|   +-- yes --> F->str = last->str          (the string moves, no copy)
|   +-- no  --> free last->str
+-- free last (the node only)
|
+-- F->str set?
    +-- yes --> KEEP, return
    +-- no  --> FINISH
                +-- prev is NULL (F is the head)? --> file_lst = F->next_file
                +-- otherwise                     --> prev->next_file = F->next_file
                +-- free F, file = NULL
```

finish needs the link that points at `F`: `file_lst` itself when `F` is the head, or the previous file node's `next_file` otherwise. `get_file_safe` records the previous file node in `prev` while it walks the list.

## Resources

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
