*This project has been created as part of the 42 curriculum by gabrlee.*

# get_next_line

## Description

get_next_line is a function that reads a file descriptor and returns one line per call, so a loop of calls walks through a file (or standard input) line by line. it keeps one list of leftovers per open file descriptor, so several file descriptors can be read in turn.

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

main implementation:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

bonus (a copy of the main implementation under the `_bonus` names the subject asks for):

```bash
cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

`main.c` is your own test program. there is no Makefile in this folder.

`BUFFER_SIZE` sets how many bytes each `read()` call asks for. try `1`, `9999` and `10000000`. without `-D BUFFER_SIZE=...`, the default of 42 set in the header is used.

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

every returned line is malloc'd, the caller has to free it. for the bonus, include `get_next_line_bonus.h` instead.

## Files

| file | content |
|---|---|
| `get_next_line.c` | `get_next_line`, `get_file_safe`, `read_and_create_safe`, `build_line`, `keep_leftover` |
| `get_next_line_utils.c` | `alloc_line`, `new_node`, `remove_file`, `ft_strchr_safe`, `ft_strlen_safe` |
| `get_next_line.h` | `t_node`, prototypes, default `BUFFER_SIZE` |
| `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h` | identical to the three files above, only the file names and the header guard differ |
| `get_next_line_stash.c`, `get_next_line_utils_stash.c`, `get_next_line_stash.h` | the previous single-fd implementation, kept for reference, see [previous implementation](#previous-implementation-stash) |

## Helper functions

`get_file_safe`, `read_and_create_safe`, `build_line` and `keep_leftover` are in `get_next_line.c`. the helpers below are in `get_next_line_utils.c`.

| function | description |
|---|---|
| `new_node` | allocates a node and copies `str` into it (`NULL` gives `""`), `next_file` and `next_buffer` are `NULL` |
| `alloc_line` | counts the length of the line and mallocs it (`NULL` if `res < 0` or malloc fails) |
| `remove_file` | unlinks a file node from the file list and frees it |
| `ft_strchr_safe` | `strchr` that accepts `NULL` |
| `ft_strlen_safe` | `strlen` that accepts `NULL` |

## Algorithm

`read()` pulls `BUFFER_SIZE` bytes at a time, so one read can return more than one line. each `read()` result is kept in its own node, and the nodes of one file descriptor are chained until a `\n` is found. the list of files is `file_lst`, a `static t_node *` inside `get_next_line`. a static starts as `NULL`, so it needs no initialisation.

each node contains:

| field | holds |
|---|---|
| `fd` | the file descriptor the node belongs to |
| `str` | a string: the leftover of a file node, or the bytes of one `read()` call in a buffer node, null terminated |
| `next_file` | the next file node. only file nodes use it, it is `NULL` on buffer nodes |
| `next_buffer` | the next node with the same `fd`. only used during one call |

there is one file node per open fd. between calls a file node holds only the leftover in `str` and `next_buffer` is `NULL`. during a call, one buffer node per `read()` is chained after the file node.

```
between calls                          during a call on fd 3

file_lst                               file_lst
  |                                      |
  v                                      v
[fd 3] --next_file--> [fd 4] --> NULL  [fd 3] --next_file--> [fd 4] --> NULL
 str = leftover        str = leftover    |
                                       next_buffer
                                         |
                                         v
                                       [fd 3] --next_buffer--> [fd 3] --> NULL
                                        read 1                  read 2
```

```
get_next_line(fd)
|
+-- fd < 0 or BUFFER_SIZE <= 0 --> return NULL
|
+-- get_file_safe(fd, &file_lst, &prev)
|   +-- list empty?              --> create file node, it becomes file_lst
|   +-- file node for fd found?  --> return it
|   +-- not found                --> create file node, append it at the end with next_file
|   `prev` is set to the file node that points at the returned node (NULL if it is the head)
|
+-- read_and_create_safe(file node)
|   |
|   +-- malloc buffer of BUFFER_SIZE + 1       (fails --> return -1)
|   +-- while no '\n' in the last node's str
|   |   +-- read(fd, buffer, BUFFER_SIZE), buffer[res] = '\0'
|   |   |   +-- -1 (error) --> return -1
|   |   |   +-- 0  (EOF)   --> return 0
|   |   +-- new_node(fd, buffer) chained with next_buffer   (fails --> return -1)
|   +-- '\n' found --> return 1
|
+-- build_line(&file node, res)
|   |
|   +-- alloc_line
|   |   +-- res < 0 --> NULL
|   |   +-- len = length of str in every node except the last
|   |   |       + last node: its whole length if res == 0,
|   |   |         else up to and including '\n'
|   |   +-- malloc(len + 1)
|   +-- copy each node's str into line until len bytes are copied
|   +-- len > 0: append a leftover node L after the last node,
|   |   L = copy of the last node's str after the copied part
|   +-- line missing, len == 0 or L not created --> free line, return NULL
|   +-- return line
|
+-- line is NULL --> res = -1
|
+-- keep_leftover(&file_lst, &file node, res, &prev)
    |
    +-- free every node between the file node and the last one
    +-- free file node's str, next_buffer = NULL
    +-- res == 1 and last node's str is not empty --> file node's str = last node's str
    |   otherwise free last node's str
    +-- free last node
    +-- file node's str is NULL --> remove_file (unlink and free the file node)
```

### cleanup cases

every call ends in one of two outcomes: **keep** the file node with the leftover, or **finish** the fd by removing its file node. two facts decide which: `res`, and whether the leftover node (`L`) holds any bytes.

| `res` | chain at cleanup | example | returns | file node after |
|---|---|---|---|---|
| 1 | `F -> buffers... -> L("cd")` | `ab\ncd`, call 1 | the line | keep: `F("cd")`, `next_buffer` NULL |
| 1 | `F -> L("cd\n")` (no buffer nodes, F already held a `\n`) | `ab\ncd\n` with a large buffer, call 2 | the line | keep |
| 1 | `F -> buffers... -> L("")` | `ab\n`, call 1 | the line | finish (nothing left) |
| 0 | `F -> buffers... -> L("")` | `abc`, call 1 | `"abc"` | finish |
| 0 | `F` alone | call after the last line, or empty file | `NULL` | finish |
| -1 | `F` alone, or `F -> buffers...` | `read` or `malloc` error | `NULL` | finish |
| any | `build_line` fails to create `L` | out of memory | `NULL` (line freed, `res` set to -1) | finish |

`F` is the file node, buffer nodes are the nodes made by each `read()`, `L` is the leftover node made by `build_line`.

```
                 keep_leftover
                        |
        free every node between F and the last one (L)
                        |
              res == 1 and L's str not empty?
                 /                  \
               yes                   no
                |                     |
              KEEP                  FINISH
   F->str = L's str          free L's str,
   F->next_buffer = NULL     F->str is NULL,
   free L's node             remove_file frees F
                             and unlinks it
```

`remove_file` needs the link that points at `F`: `file_lst` itself when `prev` is `NULL`, otherwise `prev->next_file`.

## ~~Previous implementation (stash)~~

~~replaced by the linked list implementation above. it only handles one file descriptor at a time because the leftover lives in a single static string. files: `get_next_line_stash.c`, `get_next_line_utils_stash.c`, `get_next_line_stash.h`.~~

~~`read()` pulls `BUFFER_SIZE` bytes at a time, so one read can return more than one line. there is no separate `line` buffer that grows across reads. everything read and not yet returned is stored in `stash`, a `static char *` that survives between calls.~~

| ~~function~~ | ~~description~~ |
|---|---|
| ~~`read_next_line`~~ | ~~allocates a buffer, reads `BUFFER_SIZE` bytes, appends them to `stash`, repeats until `stash` has a `\n`. returns `1` (`\n` found), `0` (EOF), `-1` (error)~~ |
| ~~`extract_line`~~ | ~~cuts the line (with its `\n`) out of the copy of `stash` and stores the rest as the new `stash`~~ |
| ~~`ft_strjoin_safe_and_free`~~ | ~~joins two strings into a new one, treats `NULL` as `""`, frees the pointers passed as `fs1` and `fs2` (also on malloc failure)~~ |
| ~~`free_all`~~ | ~~frees up to three `char *` and sets them to `NULL`~~ |
| ~~`ft_strchr_safe`~~ | ~~`strchr` that accepts `NULL`~~ |
| ~~`ft_strlen_safe`~~ | ~~`strlen` that accepts `NULL`~~ |

~~`extract_line` is in `get_next_line_stash.c`, the other functions are in `get_next_line_utils_stash.c`.~~

```
get_next_line(fd)
|
+-- fd < 0 or BUFFER_SIZE <= 0 --> free stash --> return NULL
|
+-- temp = copy of stash        (malloc fails --> free stash --> return NULL)
|
+-- '\n' in temp?
|   +-- yes --> extract_line --> return line
|   +-- no  --> read_next_line(fd, &stash)
|
+-- read_next_line result
    +--  1 --> free temp, call get_next_line(fd) again
    |        (stash now holds a '\n', so the next call ends in extract_line)
    +--  0 (EOF), stash not empty --> return a copy of stash, free stash and temp
    +--  0 (EOF), stash empty     --> free temp and stash --> return NULL
    +-- -1 (error)                --> free temp and stash --> return NULL
```

```
read_next_line(fd, &stash)
|
+-- malloc buffer of BUFFER_SIZE + 1       (fails --> return -1)
+-- read(fd, buffer, BUFFER_SIZE)
|   +-- -1 (error) --> free buffer --> return -1
|   +-- 0  (EOF)   --> free buffer --> return 0
|
+-- buffer[res] = '\0'
+-- temp = copy of stash, old stash freed
+-- stash = temp + buffer, temp and buffer freed   (any malloc failure --> return -1)
+-- '\n' in stash?
    +-- yes --> return 1
    +-- no  --> read_next_line again
```

```
extract_line(&stash, &temp, newline)
|
+-- *newline = '\0'
+-- line  = temp + "\n", old stash freed
+-- stash = copy of what is after the '\n', temp freed
+-- return line
```

| ~~state~~ | ~~what lives where~~ |
|---|---|
| ~~stash~~ | ~~every byte read and not yet returned~~ |
| ~~temp~~ | ~~a copy of stash used for one call, freed before the call returns~~ |
| ~~returned line~~ | ~~allocated only at the moment of return, freed by the caller~~ |
| ~~buffer~~ | ~~allocated and freed inside every `read_next_line` call~~ |

~~`ft_strjoin_safe_and_free` allocates the result and frees the pointers it is given, so no old string is left behind after a join. each read costs two allocations in `stash` (the copy and the joined string).~~

## Resources

- [static variables in C](https://en.cppreference.com/w/c/language/storage_duration), storage duration, the concept the subject points to

### AI usage

used Claude (Claude Code) for:
- drafting this README
