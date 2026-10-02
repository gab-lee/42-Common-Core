*This project has been created as part of the 42 curriculum by gabrlee.*

# Libft

## Description

libft is my own C library, built from scratch as the first project of the Common Core at 42. it reimplements a bunch of standard libc functions.

[github page](https://github.com/gab-lee/42-Common-Core)

## Instructions

### compile the library

```bash
make        # builds libft.a (mandatory part)
make all    # same as make
make clean  # removes object files
make fclean # removes object files + libft.a
make re     # fclean + rebuild
```

this produces `libft.a` at the root of the repo, built with `ar`.

### use it in another project

copy the `libft` folder into your project, then in your project's Makefile:

```makefile
libft/libft.a:
	make -C libft

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

| # | function | description |
|---|---|---|
| 1 | `ft_isalpha` | checks if a char is alphabetic |
| 2 | `ft_isdigit` | checks if a char is a digit |
| 3 | `ft_isalnum` | checks if a char is alphanumeric |
| 4 | `ft_isascii` | checks if a char is in the ASCII range |
| 5 | `ft_isprint` | checks if a char is printable |
| 6 | `ft_strlen` | returns the length of a string |
| 7 | `ft_memset` | fills a memory area with a byte |
| 8 | `ft_bzero` | zeroes out a memory area |
| 9 | `ft_memcpy` | copies a memory area |
| 10 | `ft_memmove` | copies a memory area, handles overlap |
| 11 | `ft_strlcpy` | copies a string, size-bounded |
| 12 | `ft_strlcat` | concatenates a string, size-bounded |
| 13 | `ft_toupper` | converts a char to uppercase |
| 14 | `ft_tolower` | converts a char to lowercase |
| 15 | `ft_strchr` | finds first occurrence of a char in a string |
| 16 | `ft_strrchr` | finds last occurrence of a char in a string |
| 17 | `ft_strncmp` | compares two strings up to n chars |
| 18 | `ft_memchr` | finds a byte in a memory area |
| 19 | `ft_memcmp` | compares two memory areas |
| 20 | `ft_strnstr` | finds a substring within n chars |
| 21 | `ft_atoi` | converts a string to an int |
| 22 | `ft_calloc` | allocates and zeroes memory |
| 23 | `ft_strdup` | duplicates a string |

### part 2 — additional functions

| # | function | description |
|---|---|---|
| 24 | `ft_substr` | allocates and returns a substring |
| 25 | `ft_strjoin` | allocates and returns the concatenation of two strings |
| 26 | `ft_strtrim` | trims chars from the start/end of a string |
| 27 | `ft_split` | splits a string into an array of strings by delimiter |
| 28 | `ft_itoa` | converts an int to a string |
| 29 | `ft_strmapi` | applies a function to each char of a string, returns a new string |
| 30 | `ft_striteri` | applies a function to each char of a string in place |
| 31 | `ft_putchar_fd` | writes a char to a file descriptor |
| 32 | `ft_putstr_fd` | writes a string to a file descriptor |
| 33 | `ft_putendl_fd` | writes a string + newline to a file descriptor |
| 34 | `ft_putnbr_fd` | writes an int to a file descriptor |

### part 3 — linked list

| # | function | description |
|---|---|---|
| 35 | `ft_lstnew` | creates a new list node |
| 36 | `ft_lstadd_front` | adds a node at the front of the list |
| 37 | `ft_lstsize` | counts the nodes in a list |
| 38 | `ft_lstlast` | returns the last node of a list |
| 39 | `ft_lstadd_back` | adds a node at the end of the list |
| 40 | `ft_lstdelone` | frees a single node and its content |
| 41 | `ft_lstclear` | frees a whole list and its content |
| 42 | `ft_lstiter` | applies a function to each node's content |
| 43 | `ft_lstmap` | applies a function to each node's content, returns a new list |

## Resources

- [Linux man pages](https://man7.org/linux/man-pages/) — the actual behaviour spec for every part 1 function
- [mini-moulinette](https://github.com/gab-lee/mini-moulinette) — the testing tool I'm currently building to check this library

### AI usage

used Claude (Claude Code) for:
- checking my finished `libft.h` prototypes against the subject's required function list to catch anything missing or extra
- drafting this README
- running norminette and `-Wall -Wextra -Werror` compile checks, and testing every function against libc
- reviewing my code: it pointed out bugs (an out-of-bounds read in `ft_strtrim`, `malloc` use in `ft_memmove`) and places where I could reuse my own libft functions
- talking through how `ft_memmove` handles overlapping memory

no function implementation was written or fixed by AI — all the `.c` logic is mine.
