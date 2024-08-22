# Simple Shell

## Description
 
'simple_shell' is a minimal implementation of a UNIX command line interpreter witten in C. This project is designed to help understand the fundamentals of creating a    shell, including process management, error handling, and end-of-file (EOF) handling.



## Project Goals
 

 - **Learn process management in C**: Using 'fork()', 'execve()', and wait()'.
 
 - **Understand error handling**: Managing errors related to command not found and other system errors.
 
 - **Handle user input**: Reading and processing user-enter commands.


## Features


 - Displays a prompt and waits for the user to enter a command.
 
 - Executes commands entered by the user.
 
 - Handles errors when the command is not found.
 
 - Supports simple commands without arguments.
 
 - Handles end-of-file (EOF) condition with `Ctrl+D`.
 
 - Implements the built-in `exit` command to exit the shell.


## Compilation


 To compile the shell, use the following command:

```bash

 gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hshi


## Running Commands


You can run the following commands in the shell:

```bash
$ ls
$ /bin/ls
$ echo "Hello, World!"
$ env        # Display the current environment variables
$ exit       # Exit the shell


## Author 


[@SeasonofBeaver](https://github.com/SeasonofBeaver)

[@Tissem-ben](https://github.com/Tissem-Ben)
