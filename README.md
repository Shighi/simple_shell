# Simple Shell

A basic UNIX command line interpreter implemented in C.

## Description

This project is a simple UNIX command line interpreter, also known as a shell. It provides a command line interface for users to interact with the operating system. The shell can execute commands, manage processes, and handle basic input/output operations.

## Features

- Execute system commands and programs
- Handle built-in commands (exit, env, setenv, unsetenv, cd, alias)
- Support for command line arguments
- Environment variable expansion
- Handle the PATH environment variable
- Implement logical operators (&& and ||)
- Support for comments (#)
- Handle the Ctrl+C signal to prevent shell from exiting
- Read commands from a file

## Built-in Commands

- `exit`: Exit the shell
- `env`: Print the current environment
- `setenv`: Set an environment variable
- `unsetenv`: Unset an environment variable
- `cd`: Change the current directory
- `alias`: Define or print aliases

## Compilation

To compile the shell, use the following command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage

To start the shell in interactive mode:
./hsh

To use the shell in non-interactive mode:
echo "command" | ./hsh
Copy
Or to execute commands from a file:
./hsh script_file

## Examples

Interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
$

Non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

## Authors
Daisy Mwambi

 Kwame Amukhobu
