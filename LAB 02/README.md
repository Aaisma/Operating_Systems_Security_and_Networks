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

| Task  |  Folder | File | Description  |
|-------|---------|---------------------|
| 1 & 2 | `task1` | `helloworld.c`      | Prints "Hello, World!"; exit status checked with `return 0` and `return 1`
| 3     | `task2` | `userinput.c`       | Reads an integer with `scanf` and prints it back
| 3     | `task3` | `userinfo.c`        | Reads name, age, and height and prints formatted output
| 4     | `task4` | copies of the above | Step-by-step compilation of each program
| 5     | `task5` | `return.c`          | Returns **50**; confirmed with `echo $?`

## Four Stages of Compilation

| Stage            | Command                   | Output                 |
|------------------|---------------------------|------------------------|
| 1. Preprocessing | `gcc -E file.c -o file.i` | `.i` (expanded source) |
| 2. Compilation   | `gcc -S file.i -o file.s` | `.s` (assembly)        |
| 3. Assembly      | `gcc -c file.s -o file.o` | `.o` (object file)     |
| 4. Linking       | `gcc file.o -o file`      | executable             |

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
