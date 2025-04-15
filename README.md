<div align="center">

# 🐚 Holberton Simple Shell


  <img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExenJlN24wYTVxMHM3ZnVyem9zeGJoOW1xcW8zMGxpeGpscWZybjJmNyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/13HgwGsXF0aiGY/giphy.gif" width="400">


## Description

This simple shell was created by maram and Hessah as a project for Holberton School of Computer Science. It is a simple UNIX command interpreter written in the C programming language. The program uses bash commands it retrieves from the command line interface (CLI) that are inputed by the user. The shell can be run in interactive and non interactive mode as shown below.


---


## 🧠 What It Does

Displays a prompt and waits for user input  
Executes commands like `/bin/ls`, `pwd`, `echo Hello`  
Handles commands with arguments like `ls -l` or `echo text`  
Uses the `PATH` environment variable to find executables (`ls`, `env`)  
Supports built-in commands: `exit`, `env`  
Works in both **interactive** and **non-interactive** modes


---

## 🖼️ Shell Flowchart

![image](https://github.com/user-attachments/assets/aefc5416-9cf8-4ad0-bf3a-470029c3bc33)

---

## 🛠️ How to Compile

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh


