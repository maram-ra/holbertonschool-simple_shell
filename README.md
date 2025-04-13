<div align="center">

# 🐚 Holberton Simple Shell


  <img src="https://media3.giphy.com/media/v1.Y2lkPTc5MGI3NjExcG5zNDhlc2RpYmpsZ3hoeWU2bXBtdTE2MHFtN2JlZXQ1cTVsYWxvZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/QDjpIL6oNCVZ4qzGs7/giphy.gif" width="400">


## Description

This simple shell was created by maram and Hessah as a project for Holberton School of Computer Science. It is a simple UNIX command interpreter written in the C programming language. The program uses bash commands it retrieves from the command line interface (CLI) that are inputed by the user. The shell can be run in interactive and non interactive mode as shown below.


---


## 🧠 What It Does

This shell:
- Displays a prompt and waits for user input
- Executes commands like `/bin/ls`, `pwd`, `echo Hello`
- Handles commands with arguments (`ls -l`, `echo text`)
- Uses the `PATH` environment to find executables (`ls`, `env`)
- Supports built-in commands: `exit`, `env`
- Works in both **interactive** and **non-interactive** mode

---

## 🖼️ Shell Flowchart

This diagram shows how the shell works internally:

![Shell Flowchart](https://raw.githubusercontent.com/YOUR_USERNAME/YOUR_REPO/main/image.png)

---

## 🛠️ How to Compile

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh


</div>
