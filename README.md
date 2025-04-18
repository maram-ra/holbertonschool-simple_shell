<div align="center">

 <img src="https://github.com/user-attachments/assets/5f8d33ce-fed8-438a-935c-a9916afef26e" width="400">
 
# 🐚 Holberton Simple Shell


  <img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExenJlN24wYTVxMHM3ZnVyem9zeGJoOW1xcW8zMGxpeGpscWZybjJmNyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/13HgwGsXF0aiGY/giphy.gif" width="400">
</div>

## Description

This simple shell was created by Maram and Hessah as a project for Holberton School of Computer Science. It is a simple UNIX command interpreter written in the C programming language. The program uses bash commands it retrieves from the command line interface (CLI) that are inputed by the user. The shell can be run in interactive and non interactive mode as shown below.


---


## Features

- Display a prompt and wait for the user to type a command
- Handle simple commands with arguments (e.g. `ls -l /tmp`)
- Execute commands using `execve`
- Handle the `PATH` environment variable to locate commands
- Support relative and absolute paths (e.g. `/bin/ls`, `./my_script`)
- Built-in commands:
  - `exit`: exits the shell
  - `env`: prints the current environment variables
- Ignore empty or whitespace-only inputs
- Handle command not found errors with proper exit status `127`


---

## Shell Flowchart



---

## 🛠️ How to Compile

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
----
## 🗂️ Project Structure

| **File**         | **Description**                                      |
|------------------|------------------------------------------------------|
| `main.c`         | Entry point, runs the shell loop and handles input   |
| `shell.h`        | Header file with all function prototypes and macros  |
| `utils.c`        | Helper functions for string manipulation and checking|
| `parser.c`       | Functions to parse and tokenize user input           |
| `path.c`         | Finds command paths by searching the `PATH` variable|
| `builtins.c`     | Built-in command implementations (`exit`, `env`)     |

## 🔧 Function Prototypes & Descriptions
| **Prototype**                                      | **Description**                                           |
|----------------------------------------------------|-----------------------------------------------------------|
| `int main(void);`                                  | Entry point of the shell program                          |
| `int only_spaces(char *s);`                        | Checks if the line is only whitespace                     |
| `void parse_arguments(char *line, char **args);`   | Splits input line into command/arguments                  |
| `char *find_command_path(char *command);`          | Searches for an executable in the `PATH`                  |
| `int handle_command(char **args);`                 | Executes a command using `fork` and `execve`              |
| `void execute_command(char *path_cmd, char **args);`| Executes command if path is valid                        |
| `char *get_env_value(const char *name);`           | Retrieves the value of an environment variable            |
| `char *_strdup(const char *str);`                  | Duplicates a string (custom `_strdup`)                    |
| `int _strlen(const char *s);`                      | Calculates the length of a string                         |
| `int _strncmp(const char *s1, const char *s2, size_t n);` | Compares strings up to `n` characters           |
| `void print_env(void);`                            | Prints current environment variables                      |


## 📚 Tasks Breakdown
####  0. README, man, AUTHORS
- You are reading it now ✨

- Created `man_1_simple_shell` and `AUTHORS` file
- See the manual:

```bash
man ./hsh.1

```

#### 1. Betty would be proud
- All code follows Holberton’s Betty style:

- Max 5 functions per file

- Max 40 lines per function (unless justified)

- No global variables

- Proper header comments

#### 2. Simple shell 0.1
- Reads user input from `stdin`

- Parses input into tokens

- Executes commands using `execve`

- Forks a new process for each command

#### 3. Simple shell 0.2
- Handles command not found errors

- Exits gracefully with correct status code

- Prompts `$` in interactive mode

#### 4. Simple shell 0.3
- Handles PATH search:

- Splits `PATH` variable into directories

- Appends command to each directory

- Checks if file exists and is executable

#### 5. Simple shell 0.4
- Implements `exit` built-in

- Ends shell with optional status code

- Implements `env` built-in

- Prints current environment variables

#### 6. Simple shell 1.0
- Shell supports all of the above in both interactive and non-interactive modes:

```bash
echo "ls -l" | ./hsh
```

## 🔧 Usage
```bash
$ ./hsh
$ ls
$ pwd
$ env
$ exit
```
