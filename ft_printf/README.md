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

#### Justification

### Technical choices

## Instructions

### Compilation

### Usage

## Resources

### References

### Use of AI
