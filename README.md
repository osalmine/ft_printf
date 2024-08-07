# ft_printf
Hive - ft_printf

> Because I’m tired of using putnbr and putstr

Grade:

[![osalmine's 42 push_swap Score: 112/100](https://badge42.coday.fr/api/v2/clysm3yyz5816201p4sqs880rw/project/1759869)](https://github.com/Coday-meric/badge42)

In this project I recoded the printf function. It creates a libftprintf.a library once compiled using:

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

See [subject](ft_printf.en.pdf) for more details.

**Bonuses**

```%b``` : prints the number in binary (base 2)

```%a``` : prints a NULL-terminated 2d array (char**)


It has functionality for **precision** (e.g %.3s) and **field-width** (e.g %3s). Width and precision work with * also (e.g "%.*s", 3)

My ft_printf works with the following length flags:

| Flags | d, i        |    o, u, x, X      | f      | a (bonus) |
| ----- | ----------- | ------------------ | ------ | --------- |
| h     | short       | unsigned short     |        |           |
| hh    | signed char | unsigned char      |        | print strings on the same line  |
| l     | long        | unsigned long      | double |   |
| ll    | long long   | unsigned long long |        |   |
| z     | size_t      | size_t             |        |   |
| L     |             |                    | long double |   |

It works also with the following flags:

**#** for o, x, X, b: value is preceeded with 0, 0x, 0X, 0b

**-** : left-justify the field width

**+** : forces to precede with + or -

**0** : left-pads the field width with zeroes instead of spaces.

**[space]** : If no sign is going to be written, insert blank before the number

**Other bonuses**

Colours: see ft_printf.h for full list of colours, but they can be used in the following way
```ft_printf(RED BG_BLACK "This string is in red\n" RESET );```
You can also insert colours in the middle using ```%s```:
```ft_printf("%sThis is red, %sThis is blue\n" RESET, RED, BLUE );```


Change the file descriptor that ft_printf prints to and can be used as such (similar to fprintf):
```ft_fprintf(fd, "This string goes to different fd!\n");```

**Some issues:**
%f flag doesn't work with some floats with high precision (over 20), but should work with almost every.
The function isn't super fast compared to the original printf as I did it with a complicated struct and not in bitwise.
