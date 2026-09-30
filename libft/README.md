*This project has been created as part of the 42 curriculum by gabrlee.*

# Libft

## Description

libft is my own C library, built from scratch as the first project of the 42 core curriculum. it reimplements a bunch of standard libc functions (string, memory, character checks) plus a set of extra helper functions and a linked list toolkit that aren't in libc at all.

the point isn't the library itself — it's understanding how these functions actually work under the hood instead of just calling them. i'll be reusing this library in basically every C project after this one.

it's split into 3 parts:
- **part 1** — reimplementations of libc functions (`strlen`, `memcpy`, `atoi`, etc.)
- **part 2** — extra string/array utilities that libc doesn't provide (`split`, `substr`, `itoa`, etc.)
- **part 3** — a singly linked list (`t_list`) and functions to manipulate it

## Instructions

### compile the library

```bash
make        # builds libft.a (mandatory part)
make bonus  # builds libft.a with the linked list functions included
make clean  # removes object files
make fclean # removes object files + libft.a
make re     # fclean + rebuild
```

this produces `libft.a` at the root of the repo, built with `ar`.

### use it in another project

copy the `libft` folder into your project, then in your project's Makefile:

```makefile
libft/libft.a:
	make -C libft bonus

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)
```

and include the header where needed:

```c
#include "libft/libft.h"
```

every function follows the same prototype/behaviour as its libc counterpart, just prefixed with `ft_`.

## Library content

### part 1 — libc functions

| function | description |
|---|---|
| `ft_isalpha` | checks if a char is alphabetic |
| `ft_isdigit` | checks if a char is a digit |
| `ft_isalnum` | checks if a char is alphanumeric |
| `ft_isascii` | checks if a char is in the ASCII range |
| `ft_isprint` | checks if a char is printable |
| `ft_strlen` | returns the length of a string |
| `ft_memset` | fills a memory area with a byte |
| `ft_bzero` | zeroes out a memory area |
| `ft_memcpy` | copies a memory area |
| `ft_memmove` | copies a memory area, handles overlap |
| `ft_strlcpy` | copies a string, size-bounded |
| `ft_strlcat` | concatenates a string, size-bounded |
| `ft_toupper` | converts a char to uppercase |
| `ft_tolower` | converts a char to lowercase |
| `ft_strchr` | finds first occurrence of a char in a string |
| `ft_strrchr` | finds last occurrence of a char in a string |
| `ft_strncmp` | compares two strings up to n chars |
| `ft_memchr` | finds a byte in a memory area |
| `ft_memcmp` | compares two memory areas |
| `ft_strnstr` | finds a substring within n chars |
| `ft_atoi` | converts a string to an int |
| `ft_calloc` | allocates and zeroes memory |
| `ft_strdup` | duplicates a string |

### part 2 — additional functions

| function | description |
|---|---|
| `ft_substr` | allocates and returns a substring |
| `ft_strjoin` | allocates and returns the concatenation of two strings |
| `ft_strtrim` | trims chars from the start/end of a string |
| `ft_split` | splits a string into an array of strings by delimiter |
| `ft_itoa` | converts an int to a string |
| `ft_strmapi` | applies a function to each char of a string, returns a new string |
| `ft_striteri` | applies a function to each char of a string in place |
| `ft_putchar_fd` | writes a char to a file descriptor |
| `ft_putstr_fd` | writes a string to a file descriptor |
| `ft_putendl_fd` | writes a string + newline to a file descriptor |
| `ft_putnbr_fd` | writes an int to a file descriptor |

### part 3 — linked list

| function | description |
|---|---|
| `ft_lstnew` | creates a new list node |
| `ft_lstadd_front` | adds a node at the front of the list |
| `ft_lstsize` | counts the nodes in a list |
| `ft_lstlast` | returns the last node of a list |
| `ft_lstadd_back` | adds a node at the end of the list |
| `ft_lstdelone` | frees a single node and its content |
| `ft_lstclear` | frees a whole list and its content |
| `ft_lstiter` | applies a function to each node's content |
| `ft_lstmap` | applies a function to each node's content, returns a new list |

## Resources

- [Linux man pages](https://man7.org/linux/man-pages/) — the actual behaviour spec for every part 1 function
- [42 Norm](https://github.com/42School/norminette) — coding style rules enforced on the project
- K&R, *The C Programming Language* — general C reference
- [Beej's Guide to C](https://beej.us/guide/bgc/) — pointers, memory, malloc/free refresher

### AI usage

used Claude (Claude Code) for:
- checking my finished `libft.h` prototypes against the subject's required function list to catch anything missing or extra
- flagging unused files (`ft_strncat.c`, `ft_strcat.c`, `ft_strcmp.c`, `ft_strcpy.c`, `ft_strncpy.c`, `ft_strstr.c`) that weren't required functions and weren't wired into the Makefile, and removing them from the repo and the Makefile's `SRCS`
- drafting this README

no function implementation was written or fixed by AI — all the `.c` logic is mine.
