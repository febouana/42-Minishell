# 🐚 42 Minishell - Your Custom Shell

Welcome to the **42 Minishell** project! This project is part of the **42 curriculum**, where we build our own simple shell in C. The goal is to understand how a Unix-like shell works by recreating some of its functionalities.

---

## **📜 Project Overview**
The goal of this project is to create a minimal version of a Unix shell. This involves parsing and executing commands, handling signals, and managing process execution.

## **❗ Features**

Our shell implementation includes the following features:

- **Prompt Display**: Displays a prompt while waiting for a new command.
- **Command Execution**: Searches for and executes the correct executable (based on the PATH environment variable or using an absolute path), similar to bash.
- **Built-in Commands**: Implements the following built-in commands:
  - `echo` with the `-n` option
  - `cd` with only absolute or relative paths
  - `pwd` without any options
  - `export` without any options
  - `unset` without any options
  - `env` without any options or arguments
  - `exit` without any options
- **Quotes Handling**: Handles single `'` and double `"` quotes like bash, except for multi-line.
- **Redirections**: Implements input and output redirections `<`, `>`, and `>>` like bash, except for file descriptor aggregations.
- **Pipes**: Implements pipes `|` as in bash.
- **Environment Variables**: Supports environment variables (`$variable`) like bash.
- **Exit Status**: Supports `$?` like bash.
- **Signal Handling**: Handles `ctrl-C`, `ctrl-D`, and `ctrl-\` to display the same results as in bash.

## **⚠️ Requirements**
- Must **not** use external libraries.
- Must follow **Norminette** coding standards.
- No memory leaks allowed.
- Must include a `Makefile` with rules:
  - `all` (compile project)
  - `clean` (remove object files)
  - `fclean` (remove object files & executable)
  - `re` (recompile everything)
- **Allowed functions:**
  - `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`
  - `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`
- **Technical restrictions:**
  - No global variables allowed
  - Must compile with `-Wall -Wextra -Werror`

### **Components:**
✅ **Mandatory Part:** Implement basic shell functionalities like parsing, executing commands, handling built-ins, and redirections.  

### **Key Concepts:**
- **Process Management:** Creating and managing processes using `fork` and `execve`.
- **Signals:** Handling signals for process control.
- **Command Parsing:** Breaking down user input into commands and arguments.
- **Built-in Commands:** Implementing commands like `cd`, `echo`, `env`.

---

## 📂 Project Structure

```plaintext
42-Minishell/
├── src/
│   ├── builtins/           # Built-in commands implementation
│   ├── executor/           # Command execution logic
│   ├── parser/             # Command parsing logic
│   ├── signals/            # Signal handling
│   ├── utils/              # Utility functions
│   └── main.c              # Entry point of the shell
├── include/
│   └── minishell.h         # Header file with function prototypes and macros
└── Makefile                # Compilation instructions
```

---

## **🛠️ Installation & Usage**
To use the shell, clone the repository and compile it.

### **📥 Clone & Compile**
```sh
git clone https://github.com/febouana/42-Minishell.git
cd 42-Minishell
make
```
### **🚀 Running the Shell**
```
./minishell
```


