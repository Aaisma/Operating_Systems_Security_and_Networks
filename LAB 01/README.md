# LAB 01: Linux Fundamentals

## Introduction

This lab covers the basics of working on the Linux command line using Ubuntu (WSL). It includes everyday file handling, installing software with `apt`, and compiling a simple C program with GCC. All work was done inside a dedicated `linux_lab` directory, which was removed at the end.

## Objectives

1. Create, edit, view, copy, rename, and delete files and directories.
2. Inspect file permissions and metadata with `ls -l`.
3. Manage packages with `apt` (update, install, search).
4. Write, compile, run, and modify a C program using `gcc`, including the `-Wall` flag.
5. Clean up the workspace and verify the results.

## Tasks

- **File Operations** (`linux_lab/greeting.txt`): Created with nano, viewed with `cat`, copied to `backup.txt`, renamed to `old_greeting.txt`, then deleted.
- **File Operations** (`linux_lab/temp_dir`): Directory created with `mkdir` and removed with `rmdir`.
- **APT Management**: Updated package list, checked `build-essential`, verified GCC, searched `python3`.
- **C Compilation** (`linux_lab/hello.c`): Adds two integers; compiled normally and with `-Wall`, then edited from 10 and 5 to 100 and 200.
- **Cleanup** (`week1/linux_lab`): Listed contents with `ls -lh`, viewed `hello.c`, removed the directory with `rm -rf`.

## Commands Used

Files:
- `mkdir`, `cd`: Create and enter the lab directory
- `nano greeting.txt`: Create and edit a file
- `cat greeting.txt`: View file content
- `cp`, `mv`: Copy and rename
- `rm`, `rmdir`, `rm -rf`: Remove files and directories
- `ls -l`: Check permissions

APT:
- `sudo apt update`: Refresh package list
- `sudo apt install build-essential`: Install C toolchain
- `apt search python3`: Search for packages

GCC:
- `gcc --version`: Verify GCC
- `gcc hello.c -o hello_program`: Compile
- `gcc -Wall hello.c -o hello_program_warn`: Compile with all warnings
- `./hello_program`: Run the program

## Useful Commands

```bash
ls -l greeting.txt                 # permissions and metadata
gcc --version                      # verify GCC
gcc -Wall hello.c -o hello_program # compile with warnings
ls -lh ~/os-labs/week1/linux_lab/  # detailed listing
```

## Summary of Results

- `greeting.txt` (13 bytes) had permissions `-rw-r--r--`.
- `build-essential` was already installed; GCC version was **15.2.0**.
- `hello.c` first printed the sum of 10 and 5 (**15**), then after editing, the sum of 100 and 200 (**300**).
- The `linux_lab` directory was deleted with `rm -rf`.

## Environment

- Ubuntu on WSL
- GNU nano 8.7.1
- GCC 15.2.0
