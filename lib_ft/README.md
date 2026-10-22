*This project has been created as part of the 42 curriculum by ccascava*

# Description

The goal of this project is to recreate multiple useful functions from the standard C library from scratch.

# Instructions

Make sure to include the header file at the top of your C file:

#include "libft.h"


You can then compile your program by typing:

cc main.c libft.a


Here, main.c is the C file you created.

The project includes a Makefile to compile libft. Using the command make creates libft.a.

make — Compiles the library and creates libft.a.
make clean — Removes object files.
make fclean — Removes object files and the library.
make re — Recompiles everything.

# Resources

I used the man pages, which I found very useful, especially for the first part of the project. I also used GeeksforGeeks as a resource to better understand certain functions, their usage, and their functionality. Lastly, I used AI for similar purposes, to improve my understanding of linked lists, as well as formatting this document.

# Functions

## Character Functions
	
	- ft_isalpha
	- ft_isdigit
	- ft_isalnum
	- ft_isascii
	- ft_isprint
	- ft_toupper
	- ft_tolower

## String Functions
	
	- ft_strlen
	- ft_strchr
	- ft_strrchr
	- ft_strncmp
	- ft_strnstr
	- ft_strdup
	- ft_substr
	- ft_strjoin
	- ft_strtrim
	- ft_split
	- ft_strmapi
	- ft_striteri

## Memory Functions
	
	- ft_memset
	- ft_bzero
	- ft_memcpy
	- ft_memmove
	- ft_memchr
	- ft_memcmp
	- ft_calloc

## Conversion Functions
	
	- ft_atoi
	- ft_itoa

## Linked List Functions
	
	- ft_lstnew
	- ft_lstadd_front
	- ft_lstsize
	- ft_lstlast
	- ft_lstadd_back
	- ft_lstdelone
	- ft_lstclear
	- ft_lstiter
	- ft_lstmap

# Author

Calin Cascaval — 42 School Vienna