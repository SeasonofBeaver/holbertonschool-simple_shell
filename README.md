# Simple Shell

## Description
 
'simple_shell' is a minimal implementation of a UNIX command line interpreter witten in C. This project is designed to help understand the fundamentals of creating a shell, including process management, error handling, and end-of-file (EOF) handling.

## Project Goals 

- **Learn process management in C**: Using 'fork()', 'execve()', and wait()'.
- **Understand error handling**: Managing errors related to command not found and other system errors.
- **Handle user input**: Reading and processing user-enter commands.

## Compilation

To compile the shell, use the following command:

```bash

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
