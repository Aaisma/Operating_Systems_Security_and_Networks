# ST5003CMD – Operating Systems, Security and Networks (Labs)

**Author:** Aaisma Wagle
**Program:** BSc (Hons) Computer Science with Artificial Intelligence
**College:** Softwarica College of IT and E-commerce (in collaboration with Coventry University)
**Instructor:** Rupak Rajbanshi

## Introduction

This repository holds my lab work for the Operating Systems, Security and Networks module. All labs were done in a Linux (Ubuntu on WSL) terminal using `nano` and `gcc`. Each lab builds on the one before it, moving from basic Linux commands to how programs run and use memory.

## Labs

| Lab | Title | Focus |
|-----|-------|-------|
| 01 | Linux Fundamentals | Files, folders, `apt`, first C program |
| 02 | C Programming Basics | GCC compilation stages and exit status |
| 2.1 | C Libraries, Linking, and ELF Executable Structure | glibc, static vs dynamic linking, `readelf`, `ldd` |
| 03 | Process Lifecycles and OS Interaction | Processes, PID/PPID, exit codes, standard I/O |
| 04 | Understanding System Internals | Data type sizes and memory segments |

## Learning Objectives

### Lab 01 – Linux Fundamentals
- Create, edit, view, copy, move and delete files and directories.
- Check file permissions with `ls -l`.
- Update and install packages using `apt`.
- Compile and run a simple C program with `gcc`, including the `-Wall` flag.

### Lab 02 – C Programming Basics
- Understand the structure of a C program.
- Explain the four GCC stages: preprocessing (`.i`), compilation (`.s`), assembling (`.o`) and linking (executable).
- Use `echo $?` to read a program's exit status (0 = success, non-zero = failure).
- Explain why C is a compiled language.

### Lab 2.1 – C Libraries, Linking, and ELF Executable Structure
- Understand the two halves of the C Standard Library: header files (`/usr/include/`, declarations only) and precompiled libraries (`.a` static, `.so` shared).
- Compare static linking (`gcc -static`) vs dynamic linking, and explain the resulting file size difference.
- Inspect an executable's ELF structure with `readelf -h`, `-l` and `-d`.
- Trace shared library dependencies with `ldd`.

### Lab 03 – Process Lifecycles and OS Interaction
- See a running program as a process using `ps` and `ps aux | grep`.
- Find a process's PID and its parent's PPID with `getpid()` and `getppid()`.
- Use exit codes to send success or failure back to the OS.
- Use standard input and output (`scanf()` and `printf()`).

### Lab 04 – Understanding System Internals
- Use `sizeof()` to check data type sizes and confirm a 64-bit system.
- Explain why `long` differs between 32-bit and 64-bit systems.
- Identify the five memory segments: Text, Data, BSS, Heap and Stack.
- Print variable addresses with `%p` and see the memory layout (and the effect of ASLR).

## Tools Used
- Ubuntu on WSL
- GCC
- Nano
- Git and GitHub

## How to Compile and Run

```bash
gcc file.c -o output_name
./output_name
echo $?
```
