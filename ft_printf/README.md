*This project has been created as part of the 42 curriculum by gabrlee.*

# ft_printf

## Description

### Features

#### Mandatory conversions

#### Bonus

### Algorithm and data structure

#### Chosen approach

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

### ft_printf flags and valid conversions

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
#### Justification

### Technical choices

## Instructions

### Compilation

### Usage

## Resources

### References

### Use of AI
