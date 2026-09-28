# LAB 02: C Programming Basics

## Introduction

This lab covers the basics of C programming on Ubuntu (WSL) and shows how a program moves from source code to something the operating system can run. It includes writing small C programs, compiling them with GCC one stage at a time, and reading exit statuses with `echo $?`.

## Objectives

1. Install and verify GCC, and understand the structure of a basic C program.
2. Write programs that print output, take user input, and use formatted output.
3. Run the four GCC compilation stages separately and inspect the file each one produces.
4. Understand how `main()`'s return value becomes the exit status seen by the shell.
5. Answer the knowledge check questions on `#include`, compilation stages, and compiled vs. interpreted languages.

## Programs

- **Task 1 & 2** (`task1/helloworld.c`): Prints "Hello, World!"; exit status checked with `return 0` and `return 1`.
- **Task 3** (`task2/userinput.c`): Reads an integer with `scanf` and prints it back.
- **Task 3** (`task3/userinfo.c`): Reads name, age, and height and prints formatted output.
- **Task 4** (`task4`): Copies of the above, compiled step by step.
- **Task 5** (`task5/return.c`): Returns **50**; confirmed with `echo $?`.

## Four Stages of Compilation

1. **Preprocessing**: `gcc -E file.c -o file.i` produces a `.i` file (expanded source).
2. **Compilation**: `gcc -S file.i -o file.s` produces a `.s` file (assembly).
3. **Assembly**: `gcc -c file.s -o file.o` produces a `.o` file (object file).
4. **Linking**: `gcc file.o -o file` produces the executable.

Run with `./file`, then check the result with `echo $?`.

## Useful Commands

```bash
gcc --version        # verify GCC
file file.o          # confirm object/machine code
ls -lh               # compare file sizes across stages
echo $?              # exit status of last program
```

## Summary of Results

- GCC version **15.2.0** was already installed via `build-essential`.
- Exit status **0** means success; **1** and **50** were returned and read correctly by `echo $?`.
- `file` confirmed the `.o` files are ELF 64-bit relocatable object files.
- File sizes grew and changed across stages; the `.i` file was largest because the headers were expanded.

## Environment

- Ubuntu on WSL
- GNU nano 8.7.1
- GCC 15.2.0
