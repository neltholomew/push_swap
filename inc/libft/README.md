*This project has been created as part of the 42 curriculum by pcellar*

# libft

## Description

**libft** is a C library project from 42's core curriculum. The goal
is to re-implement a set of standard C library functions from scratch,
along with a handful of additional helper functions and a small linked-list
toolkit, and package them into a single static library, `libft.a`.

## Instructions

Clone the repository and build the library with `make`:

```sh
git clone <repo-url> libft
cd libft
make
```

This compiles every `ft_*.c` source file with `cc -Wall -Wextra -Werror`
and archives the resulting object files into `libft.a` using `ar`.

Other available Makefile rules:

| Rule      | Effect                                             |
|-----------|-----------------------------------------------------|
| `make`    | Builds `libft.a`                                    |
| `make all`| Same as `make`                                      |
| `make clean` | Removes object files                             |
| `make fclean`| Removes object files and `libft.a`               |
| `make re` | `fclean` followed by a full rebuild                  |

To use the library in another project, include the header and link
against the archive:

```sh
cc your_program.c -I/path/to/libft -L/path/to/libft -lft -o your_program
```

```c
#include "libft.h"
```

## Detailed description of the library

The header `libft.h` declares the struct used by the linked-list part:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

### Part 1 — Libc function clones

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic |
| `ft_isdigit` | Checks if a character is a digit |
| `ft_isalnum` | Checks if a character is alphanumeric |
| `ft_isascii` | Checks if a character is a valid ASCII code |
| `ft_isprint` | Checks if a character is printable |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills a memory area with a constant byte |
| `ft_bzero` | Zeroes out a memory area |
| `ft_memcpy` | Copies memory between non-overlapping areas |
| `ft_memmove` | Copies memory, safe for overlapping areas |
| `ft_strlcpy` | Copies a string, always null-terminates |
| `ft_strlcat` | Concatenates strings, always null-terminates |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strchr` | Locates the first occurrence of a character in a string |
| `ft_strrchr` | Locates the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Locates a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Locates a substring in a string, bounded by length |
| `ft_atoi` | Converts a string to an int |
| `ft_calloc` | Allocates and zero-initializes memory |
| `ft_strdup` | Duplicates a string |

### Part 2 — Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring |
| `ft_strjoin` | Allocates and returns the concatenation of two strings |
| `ft_strtrim` | Trims leading/trailing characters of a given set from a string |
| `ft_split` | Splits a string into an array of substrings |
| `ft_itoa` | Converts an int to a newly allocated string |
| `ft_strmapi` | Applies a function to each character of a string, building a new string |
| `ft_striteri` | Applies a function to each character of a string in place, with its index |
| `ft_putchar_fd` | Writes a character to a given file descriptor |
| `ft_putstr_fd` | Writes a string to a given file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline to a given file descriptor |
| `ft_putnbr_fd` | Writes an int to a given file descriptor |

### Part 3 — Linked list

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize` | Counts the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstdelone` | Frees a single node's content and the node itself |
| `ft_lstclear` | Frees an entire list, node by node |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node's content |

## Resources

- 42 Prague Libft subject PDF — the reference for
  every function's prototype and expected behavior.
- The C standard library man pages for the behavior
  each `ft_*` function reproduces.

### How AI was used

I used Claude Code as a study aid while working on this project.
Asking it to explain concepts from the subject, clarify how a libc function is expected to behave, and review my own implementations for bugs, edge cases, and Norm issues.
