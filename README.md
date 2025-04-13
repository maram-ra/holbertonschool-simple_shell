
# 🐚 Holberton Simple Shell


  <img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExNWZoYmVjd28xN3NqZGRsbGsyanI1ejNpY2FibHhremlkNHFid3p5MSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/13HgwGsXF0aiGY/giphy.gif" width="400">




## Description

This project is a simple UNIX command interpreter built as part of the Holberton School curriculum.  
It mimics the basic functionalities of the shell and helps understand low-level system programming in C.

---

## Table of Contents

[Features](#features)  
[Flowchart](#flowchart)  
[How to Use](#how-to-use)  
[Installation](#installation)  
[Authors](#authors)

---

## Features

- Command execution with arguments
- Path resolution
- Environment variable support
- Built-in commands: `exit`, `env`
- And more...

---

## Flowchart

<p align="center">
  <img src="https://github.com/maram-ra/holbertonschool-simple_shell/blob/b3627e8b4d1893be96269ee00e5d598c44b05d49/232889814-c96b5a35-7032-4b5c-8e06-4263eb0f5c2f.png"/>
</p>

---
## 📁 File Structure

This table provides a brief description of the files used in the simple shell project. Click on the file names to view their source code.

| **File**                   | **Functions**                                                                 | **Description**                                                                 |
|----------------------------|-------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
| [`shell.h`](./shell.h)     | Header of the project                                                        | Contains structures, prototypes, macros, and external variables.                |
| [`shell.c`](./shell.c)     | `int main();`                                                                | Main loop: receives input from the CLI, parses, and executes it.                |
| [`tokenizers.c`](./tokenizers.c) | `char **hsh_tokenizer();`<br>`char **tokenizer_path();`                     | Splits the input string into an array of tokens.<br>Splits the PATH environment variable into an array of tokens. |
| [`validators.c`](./validators.c) | `char *validate_input();`<br>`int validate_spaces();`                        | Validates if PATH exists.<br>Validates spaces, tabs, and line breaks.           |
| [`exe_command.c`](./exe_command.c) | `int hsh_execute();`<br>`int hsh_execute_builtins();`                        | Forks process and replaces the child with a new program.<br>Selects from an array of builtin functions. |
| [`builtins.c`](./builtins.c) | `int hsh_cd();`<br>`int hsh_setenv();`<br>`int hsh_unsetenv();`<br>`int hsh_env();`<br>`int hsh_exit();` | Changes directory.<br>Sets or adds an environment variable.<br>Deletes an environment variable.<br>Prints the environment variables list.<br>Terminates the main loop and exits the shell. |
| [`the_helpers.c`](./the_helpers.c) | `char *str_concat();`<br>`void *_realloc();`                                 | Concatenates two strings.<br>Reallocates a memory block.                        |


