*This project has been created as part of the 42 curriculum by gabrlee.*

# ft_printf

## Description

ft_printf is my own implementation of the libc `printf`, built as a Common Core project at 42. it formats its arguments according to a format string, writes the result to standard output and returns the number of bytes written.

```c
int	ft_printf(const char *str, ...);
```

| case | return |
|---|---|
| success | the number of bytes written |
| write error | `-1` |

| | functions |
|---|---|
| allowed | `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end` |
| forbidden | `printf` and the rest of the libc `printf` family |

### Features

#### Mandatory conversions

| conversion | prints |
|---|---|
| `%c` | a single character |
| `%s` | a string |
| `%p` | a pointer in hexadecimal |
| `%d` | a signed decimal integer |
| `%i` | a signed integer, same output as `%d` |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a literal percent sign |

#### Bonus

| flag | effect |
|---|---|
| `-` | left-justify within the width |
| `0` | pad with zeros instead of spaces |
| `.` | precision |
| width | minimum field width |
| `#` | `0x` / `0X` prefix |
| space | space before a non-negative number |
| `+` | always print the sign |

the full rules and the combinations that are valid per conversion are in the tables below.

## Instructions

### compile

```bash
make        # builds libftprintf.a (mandatory part)
make bonus  # builds libftprintf.a with the bonus flags
make clean  # removes object files
make fclean # removes object files + libftprintf.a
make re     # fclean + rebuild
```

then link it with your own `main.c`:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```

### use it

```c
#include "ft_printf.h"

int	n = ft_printf("age: %5d, id: %s\n", 42, "ab");
```

`n` holds the number of bytes written, `\n` included.

## Algorithm and data structure

### chosen approach

`ft_printf` walks the format string one character at a time. a plain character is written straight away. a `%` starts a conversion: every character after it is collected into a `flags` string until a conversion letter from `cspdiuxX%` is found. the letter selects the handler, the collected `flags` select the modifiers that change how the handler prints.

the variadic arguments are never copied. one `va_list` is created in `ft_printf` and passed by pointer, so each handler consumes exactly its own argument with `va_arg` and the next handler continues where it stopped. every write goes through `put_char_count` and `put_str_count`, which add to a single `bytes_written` counter, so the return value is built as the output is produced.

```
 caller:  ft_printf("age: %5d, id: %s\n", 42, "ab");

                    int ft_printf(const char *str, ...)
                    |                           |
        +-----------+                           +-------------+
        |                                                     |
        v                                                     v
  str (read-only string)                        ... (variadic arguments)
  "age: %5d, id: %s\n"                          stored in a va_list
        |                                       consumed one at a time
        |                                       with va_arg
        v
  +-----------------------------+
  | walk str one char at a time |<---------------------------------+
  +-----------------------------+                                   |
        |                                                           |
        +-- not '%' --> write char, bytes_written += 1 ------------>+
        |                                                           |
        +-- '%' --> collect chars after it until a conversion       |
                    letter (c s p d i u x X %)                      |
                                |                                   |
              +-----------------+-----------+                       |
              |                             |                       |
              v                             v                       |
     modifiers collected            conversion letter               |
     (bonus only)                   selects a case function         |
     - 0 . width # + space                  |                       |
              |                             v                       |
              |            +-----------------------------+          |
              |            | case function table         |          |
              |            |   'c' -> print_char         |          |
              |            |   's' -> print_str          |          |
              |            |   'p' -> print_ptr          |          |
              |            |   'd' -> print_int          |          |
              |            |   'i' -> print_int          |          |
              |            |   'u' -> print_uint         |          |
              |            |   'x' -> print_hex (lower)  |          |
              |            |   'X' -> print_hex (upper)  |          |
              |            |   '%' -> print_percent      |          |
              |            +-----------------------------+          |
              |                             |                       |
              +-- modifies how the -------->|                       |
                  case function works       v                       |
                                takes next arg from va_list         |
                                (none for '%')                      |
                                            |                       |
                                writes the output and               |
                                returns bytes written               |
                                            |                       |
                                bytes_written += returned --------->+

  end of str  --->  return bytes_written
```

### file structure

```
ft_printf/
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf_bonus.h
├── ft_printf.c
├── handles/                  one handler per conversion
│   ├── handle_c.c
│   ├── handle_s.c
│   ├── handle_p.c
│   ├── handle_d_or_i.c
│   ├── handle_u.c
│   ├── handle_x.c
│   ├── handle_upper_x.c
│   └── handle_percent.c
├── modifiers/                bonus flags, built only by `make bonus`
│   ├── nothing_bonus.c
│   ├── modify_width_bonus.c
│   ├── modify_dot_bonus.c
│   ├── modify_hashtag_bonus.c
│   ├── modify_width_zero_bonus.c
│   ├── modify_width_minus_bonus.c
│   ├── modify_plus_bonus.c
│   └── modify_space_bonus.c
├── utility/                  parsing, counting and formatting helpers
│   ├── handle_conversion.c
│   ├── handle_conversion_bonus.c bonus only
│   ├── call_modifiers_bonus.c    bonus only
│   ├── format_str.c
│   ├── get_hexadecimal.c
│   ├── ft_printf_utility.c
│   └── put_and_count.c
└── libft_safe/               libft functions adapted for ft_printf
    ├── ft_atoi.c
    ├── ft_strchr.c
    ├── ft_strlcpy.c
    ├── ft_strlen_safe.c
    └── strjoin_safe.c
```

### code map

| step | function | file |
|---|---|---|
| walk the format string | `ft_printf` | `ft_printf.c` |
| collect flags, find the conversion letter | `handle_conversion` | `utility/handle_conversion.c` |
| pick the handler from the letter | `call_handle` | `utility/handle_conversion.c` |
| pick the modifiers from the flags | `call_modifier` | `utility/call_modifiers_bonus.c` |
| write and count | `put_char_count`, `put_str_count` | `utility/put_and_count.c` |
| hexadecimal string | `get_hexadecimal` | `utility/get_hexadecimal.c` |

the "case function table" in the diagram is the `call_handle` function, which returns a `t_handler` function pointer:

| letter | handler | file |
|---|---|---|
| `c` | `handle_c` | `handle_c.c` |
| `s` | `handle_s` | `handle_s.c` |
| `p` | `handle_p` | `handle_p.c` |
| `d` `i` | `handle_d_or_i` | `handle_d_or_i.c` |
| `u` | `handle_u` | `handle_u.c` |
| `x` | `handle_x` | `handle_x.c` |
| `X` | `handle_upper_x` | `handle_upper_x.c` |
| `%` | `handle_percent` | `handle_percent.c` |

### helper functions

#### libft functions used (`libft_safe/`)

these are copied from my [libft](../libft) into `libft_safe/` so that `libftprintf.a` builds without linking `libft.a`. `ft_printf` can receive `NULL` (for example `%s` with a null pointer), so the functions that would crash on it are changed.

| function | original libft function | used for | remarks |
|---|---|---|---|
| `ft_atoi` | `ft_atoi` | reading width and precision from the flags | unchanged, only the included header differs |
| `ft_strchr` | `ft_strchr` | checking if a char is one of the conversion letters | unchanged, only the included header differs |
| `ft_strlcpy` | `ft_strlcpy` | copying strings while building the output | modified: calls `ft_strlen_safe` instead of `ft_strlen` |
| `ft_strlen_safe` | `ft_strlen` | string length | modified: returns `0` when the string is `NULL` |
| `strjoin_safe` | `ft_strjoin` | joining padding, prefix and digits | modified: returns `NULL` when `s1` or `s2` is `NULL`, uses `ft_strlen_safe` |

#### other helpers

| function | description |
|---|---|
| `ft_strcat_char` | appends one char to a malloc'd string, used to collect the flags |
| `ft_itoa` | signed int to string, local to `handle_d_or_i.c` |
| `uitoa` | unsigned int to string, local to `handle_u.c` |
| `get_hexadecimal` | unsigned long to a hexadecimal string, lowercase or uppercase |

`get_hexadecimal` computes the length first, allocates once and fills the string from the last digit to the first, so no reversing is needed. uppercase is applied while filling, through a function pointer.

### bonus: flags and modifiers

a modifier is a function pointer (`t_modifier`). `call_modifier` starts from a modifier that does nothing and wraps it once per flag found in `flags`, in a fixed order: width, precision, `#`, `0`, `-`, `+`, space. the same flags therefore always produce the same chain, no matter the order they were typed in the format string.

| Flag | Effect | Triggered by | Interactions |
|---|---|---|---|
| `-` | Left-justifies within the width and pads on the right with spaces | Any conversion, when a width is present | Overrides `0` |
| `0` | Pads with zeros instead of spaces up to the width | `d i u x X` | Ignored if `-` is present, and ignored for integers if a precision is given |
| `.` (precision) | `s`: maximum characters printed. Integers: minimum digits, padded with leading zeros | `s d i u x X` | A precision of 0 with value 0 prints no digits |
| width (number) | Minimum field width, padded with spaces | Any conversion | Never truncates |
| `#` | Prefixes `0x` or `0X` | `x X`, only when the value is nonzero | No effect on other conversions |
| space | Prefixes a space when the number is not negative | `d i` | Ignored if `+` is present |
| `+` | Always prints a sign | `d i` | Overrides space |

Order of application on a converted string: precision, then sign or prefix, then width padding.

| Conversion | Valid flags and modifiers | Not valid |
|---|---|---|
| `c` | `-`, width | `0`, `#`, `+`, space, precision |
| `s` | `-`, width, precision | `0`, `#`, `+`, space |
| `p` | `-`, width | `0`, `#`, `+`, space, precision |
| `d` `i` | `-`, `0`, `+`, space, width, precision | `#` |
| `u` | `-`, `0`, width, precision | `#`, `+`, space |
| `x` `X` | `-`, `0`, `#`, width, precision | `+`, space |
| `%` | none | all |

"Not valid" means the C standard leaves the behavior undefined. Most libcs ignore those combinations silently.

### justification

- one `va_list` passed by pointer keeps argument order correct without a separate argument array.
- a table of handlers keyed by the conversion letter keeps `handle_conversion` small. adding a conversion means adding a handler and one line in `call_handle`.
- modifiers are separate from handlers, so the mandatory conversions work without them and the bonus only plugs into the same call.
- the return value is counted at the single place where bytes are written, so it cannot drift from what was actually printed.

### technical choices

- `%p` and `%x` share `get_hexadecimal`, which takes an `unsigned long`.
- `%d` and `%i` share one handler, they only differ on input in `scanf`.
- integer conversions build their string with a local `itoa`, so the sign, zero padding and precision can be applied to a string afterwards.
- `INT_MIN` is handled by converting each digit with the sign factored in, instead of negating the number.
- the `flags` string is built with `malloc`, so every exit path of `handle_conversion` must free it.

## Resources

- [Linux man pages: printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html), the behaviour spec for the format string, flags and conversions
- [Linux man pages: stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html), `va_list`, `va_start`, `va_arg`, `va_end`
- [libft](../libft), my own library from the first project of the Common Core

### AI usage

used Claude (Claude Code) for:
- reviewing the current state of the code: it pointed out compile errors, index bugs and leaks
- drafting this README

no function implementation was written or fixed by AI, all the `.c` logic is mine.
