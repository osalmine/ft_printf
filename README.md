# ft_printf
Hive - ft_printf

> Because I’m tired of using putnbr and putstr

Recoded the printf function. It creates a libftprintf.a library once compiled using:

```make```

It works with the following flags:

```%c``` : prints an ascii character

```%p``` : prints the memory address of the argument

```%s``` : prints a string

```%d``` : prints a number

```%i``` : same as d

```%u``` : prints unsigned int

```%o``` : prints the number in octal (base 8)

```%x``` : prints the number in hexadecimal (base 16) with small letters

```%X``` : same as x but with big letters

```%f``` : prints floats

```%%``` : prints %

**Bonuses**

```%b``` : prints the number in binary (base 2)

```%a``` : prints a NULL-terminated 2d array (char**)


It has functionality for precision (e.g %.3s) and field-width (e.g %3s). Width and precision work with * also (e.g "%.*s", 3)

Flags:
| Flags | d, i | o, u, x, X |
|---|------|------------|
| h | short | unsigned short |
| hh | signed char | unsigned char |
| l | long | unsigned long |
| ll | long long | unsigned long long |
| z | size_t | size_t |

| Left-aligned | Center-aligned | Right-aligned |
| :---         |     :---:      |          ---: |
| git status   | git status     | git status    |
| git diff     | git diff       | git diff      |
