<div align="center">

# 🐚 Holberton Simple Shell


  <img src="https://media3.giphy.com/media/v1.Y2lkPTc5MGI3NjExcno3M2dmenpscDIzODIyc3I5N3BvZWNmM3k4emdmNWZ3ZWgxemt3dCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/QDjpIL6oNCVZ4qzGs7/giphy.gif" width="400">

## Table of Contents
<div align="center">

<a href="#description">Description</a><br>
<a href="#flowchart">Flowchart</a><br>
<a href="#file-structure">File Structure</a><br>
<a href="#system-and-library-calls">System and Library calls</a><br>
<a href="#installation">Installation</a><br>
<a href="#example-of-use">Example of Use</a><br>
<a href="#authors">Authors</a>

</div>


## Description

This simple shell was created by maram and Hessah as a project for Holberton School of Computer Science. It is a simple UNIX command interpreter written in the C programming language. The program uses bash commands it retrieves from the command line interface (CLI) that are inputed by the user. The shell can be run in interactive and non interactive mode as shown below.


---



## Flowchart

<p align="center">
  <img src="https://github.com/maram-ra/holbertonschool-simple_shell/blob/b3627e8b4d1893be96269ee00e5d598c44b05d49/232889814-c96b5a35-7032-4b5c-8e06-4263eb0f5c2f.png"/>
</p>

## File Structure

| File                | Content / Functions                                                                 | Description                                                                                   |
|---------------------|-------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| `shell.h`           | Header of the project                                                              | Contains structures, prototypes, macros, and external variables.                              |
| `shell.c`           | `int main()`                                                                        | Main loop: receives input from CLI, parses and executes it.                                   |
| `tokenizers.c`      | `char **hsh_tokenizer()`, `char **tokenizer_path()`                                 | Splits input into tokens and splits `PATH` into an array of paths.                            |
| `validators.c`      | `char *validate_input()`, `int validate_spaces()`                                   | Validates input and existence of `PATH`; checks for spaces, tabs, and line breaks.            |
| `exe_command.c`     | `int hsh_execute()`, `int hsh_execute_builtins()`                                   | Forks process and runs commands or built-ins.                                                 |
| `builtins.c`        | `hsh_cd()`, `hsh_setenv()`, `hsh_unsetenv()`, `hsh_env()`, `hsh_exit()`             | Built-in commands: change directory, manage environment variables, print environment, exit.   |
| `the_helpers.c`     | `char *str_concat()`, `void *_realloc()`                                            | Helper functions: string concatenation and memory reallocation.                               |
Structure


</div>
