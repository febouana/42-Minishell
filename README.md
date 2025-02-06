# 42-Minishell


Minishell is the first team project in the 42 common core, focused on developing a robust parsing system to interpret and execute user commands, following the POSIX Bash model. The goal is to create a basic shell in C. We must implement builtin commands such as `pwd`, `cd`, `echo`, `env`, `export`, `unset`, and `exit`, while also supporting pipes, redirections, and environment variable expansion. Additionally, a command history system allows users to navigate through previous inputs. This is our own little Bash!

## How to use

To clone the repository:
```
git clone git@github.com:justaPoet/42-Minishell.git minishell
```

To compile:

```shell
cd minishell && make
```

To run the program:

```shell
./minishell
```



## Features:

  System commands accessible from the environment (`ls`, `cat`, `grep`...etc)
  Command history navigation (using up and down arrows)
  `$?` expands to the exit status of the last executed foreground command
  Built-in commands:
  * `pwd` (no options)
  * `cd` (only with a relative or absolute path)
  * `echo` (supports the -n option)
  * `env` (no arguments or options)
  * `export` (no options)
  * `unset` (no options)
  * `exit` (accepts an exit code but no additional options)
  Pipes:
  * `|` redirects the output of one command as input for the next
  Redirections:
  * `>` redirects standard output
  * `>>` appends output to an existing file
  * `<` redirects standard input
  * `<< EOF` opens a secondary prompt, reads user input until EOF is reached, and sends it as input to the command
  Environment variables:
  * `$VAR` and `$USER` expand to their corresponding values
  User keyboard signals:
  * `Ctrl-C` interrupts the running command and displays a new prompt
  * `Ctrl-D` exits the shell if no command is running
  * `Ctrl-\` does nothing
 
---
* [1.Test suite for Minishell](https://docs.google.com/spreadsheets/d/1BPW7k81LJPhGv2fbi35NIIoOC_mGZXQQJDnV0SjulFs/edit?pli=1&gid=0#gid=0)
* [2.Test suite for Minishell](https://docs.google.com/spreadsheets/d/1uJHQu0VPsjjBkR4hxOeCMEt3AOM1Hp_SmUzPFhAH-nA/edit?gid=0#gid=0)
---

Thanks to [obouayed](https://github.com/osmaneb23), who was my partner throughout this incredibly interesting project!    🚀
