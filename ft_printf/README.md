*This project has been created as part of the 42 curriculum by gabrlee.*

# ft_printf

## Description

ft_printf is a reimplementation of the libc `printf()` function, built as a static library (`libftprintf.a`). The goal is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`) and how to structure a parser that stays easy to extend.

Prototype:

```c
int	ft_printf(const char *, ...);
```

It returns the number of characters written, or -1 on error, like `printf()`. It does not reproduce the internal buffer of the original `printf()`.

### Mandatory conversions

| conversion | output |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` for a NULL pointer) |
| `%p` | a pointer in hexadecimal, prefixed with `0x` (`(nil)` for NULL, as glibc does) |
| `%d` `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` `%X` | an unsigned hexadecimal number, lowercase or uppercase |
| `%%` | a percent sign |

### Bonus

- Flags `-`, `0` and `.`, plus the minimum field width, on the conversions.
- Flags `#`, space and `+`.

## Instructions

```bash
make          # builds libftprintf.a (mandatory part)
make bonus    # builds libftprintf.a with the bonus part
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

`make` and `make bonus` both produce `libftprintf.a`. Each one rebuilds the archive from scratch, so the last one you ran decides which version you get. The archive also contains `libft`, so only `-lftprintf` is needed to link.

Usage in another project:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("%s has %d items (%x)\n", "list", 42, 42);
	return (0);
}
```

```bash
cc main.c -I<path_to_ft_printf> -L<path_to_ft_printf> -lftprintf
```

## Algorithm and data structures

No data structure is kept between conversions. `ft_printf` walks the format string once, left to right, and handles each `%` as an independent step.

1. **Walk the string.** Normal characters are written directly. A `%` hands control to a parser, which returns the next index to resume from. Running totals live in one `bytes_written` counter passed by pointer, so every write path updates the return value in the same place.
2. **Dispatch with a function table.** `call_handle` maps a conversion character to a handler of type `char *(*)(va_list *)`. Every handler reads exactly one argument with `va_arg` and returns the converted text as a freshly allocated string. The `va_list` is passed by pointer so that each handler advances the same argument cursor.
3. **Build text first, print last.** Because every handler returns a string, the formatting rules (precision, sign, `#`, width) are plain string transformations applied afterwards. The text is written only once it is final.
4. **Bonus modifiers as a pipeline.** In the bonus build, flags between `%` and the conversion are collected into a small string, validated (`check_valid_flags`), then split into width and precision (`extract_flags`). `call_modifier` applies the steps in a fixed order: precision, sign (`+` or space), `#` prefix, then width (`-`, `0` or default space padding). Each step takes `char **` and replaces the string with a new allocation, freeing the old one.
5. **`%c` with `\0`.** A zero character cannot travel as a C string, so the mandatory path writes it with an explicit length and the bonus path uses `put_null` to handle the padding by hand.

Why this design:

- Returning a string from each handler keeps handlers tiny and testable, and keeps all flag logic out of them. Adding a conversion means adding one handler and one line in `call_handle`.
- A fixed modifier order mirrors how `printf` itself resolves flags, for example the `0` flag is ignored when a precision is present and `-` overrides `0`.
- The cost is one allocation per modifier. This is accepted in exchange for simpler code, and the original `printf()` buffer is deliberately not reproduced, as the subject requires.
- The bonus lives in separate `_bonus` files and its own `ft_printf_bonus.c`. The mandatory build never compiles them.

## Project layout

| path | content |
|---|---|
| `ft_printf.c`, `ft_printf.h` | entry point and header (mandatory) |
| `ft_printf_bonus.c`, `ft_printf_bonus.h` | entry point and header (bonus) |
| `handles/` | one handler per conversion, plus `get_hexadecimal` |
| `parse/` | conversion dispatch and flag parsing |
| `modifiers/` | bonus flag, width and precision logic |
| `utility/` | output counting and small string helpers |
| `libft/` | copy of my libft, built by this Makefile |

## Known limitations

- Behaviour for invalid format strings (for example `%y`) is undefined in C and does not match glibc.
- `%p` combined with precision, `0`, `+` or space, and a few edge cases such as `%.3s` with NULL, are not yet identical to glibc.

## Resources

- [printf(3) man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) man page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [The GNU C Library: Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- [libft](https://github.com/gab-lee/42-Common-Core), the library whose functions this project reuses

### AI usage

Claude (Claude Code) was used for:
- auditing the finished code: running norminette, compile checks, valgrind and ASan, and comparing the output of `ft_printf` against glibc `printf` over a large set of flag combinations to find mismatches and leaks
- reviewing the Makefile and file naming against the subject
- drafting and updating this README
- renaming the bonus files and fixing a typo in the header

The `ft_printf` source code itself was written by me.
