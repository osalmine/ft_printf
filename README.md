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

My ft_printf works with the following length flags:

| Flags | d, i        |    o, u, x, X      | f      |
| ----- | ----------- | ------------------ | ------ |
| h     | short       | unsigned short     |        |
| hh    | signed char | unsigned char      |        |
| l     | long        | unsigned long      | double |
| ll    | long long   | unsigned long long |        |
| z     | size_t      | size_t             |        |
| L     |             |                    | long double |

It works also with the following flags:

**#** for o, x, X: value is preceeded with 0, 0x, 0X
**-** : left-justify the field width
**+** : forces to precede with + or -
**0** : left-pads the field width with zeroes instead of spaces.
**[space]** : If no sign is going to be written, insert blank before the number
