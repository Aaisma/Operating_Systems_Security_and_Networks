# LAB 04: A Practical Approach to Understanding System Internals

## Introduction

This lab looks at how data types and memory layout work inside an operating system. A data type decides how much memory a variable uses, and the OS divides a process's memory into segments: Text, Data, BSS, Heap, and Stack. Two C programs were written and run on Ubuntu (WSL): one uses `sizeof()` to check data type sizes, and the other prints variable addresses to see how segments are arranged. All work is inside a folder called `LAB 04`.

## Objectives

1. Use `sizeof()` to find the size of common data types on the system.
2. Compare the results with the 16-bit, 32-bit, and 64-bit table to identify the system architecture.
3. Declare variables in the Data, BSS, Stack, and Heap segments and print their addresses with `%p`.
4. Identify which segment has the highest and lowest addresses and calculate the stack-heap gap.
5. Answer the knowledge check questions on data types and memory segments.

## Programs

| Task  | Folder  | File     | Description 
|-------|---------|----------|
| Lab 1 | `task1` | `lab1.c` | Prints the size of `char`, `int`, `float`, `double`, `long`, pointer, `unsigned int`, and `long long` 
| Lab 2 | `task2` | `lab2.c` | Prints addresses of a global initialized, global uninitialized, local, and `malloc` variable, then the stack-heap difference 

## Memory Segments

| Segment | Stores                                              | Variable in `lab2.c` 
|---------|-----------------------------------------------------|
| Text    | Machine code                                        |  none 
| Data    | Initialized globals and statics                     | `global_init` 
| BSS     | Uninitialized globals and statics (zeroed at start) | `global_uninit` 
| Heap    | Memory from `malloc`, grows upward                  | `heap_var` 
| Stack   | Local variables and function calls, grows downward  | `local_var` 

## Commands Used

| Category | Command              | Purpose 
|----------|----------------------|
| Files    | `mkdir`, `cd`        | Create and enter folders 
| Files    | `nano lab1.c`        | Write or edit a C file 
| Files    | `cat lab1.c`         | View file contents 
| GCC      | `gcc lab1.c -o lab1` | Compile the program 
| Run      | `./lab1`             | Run the program 

## Useful Commands

```bash
gcc lab1.c -o lab1    # compile
./lab1                # data type sizes
gcc lab2.c -o lab2    # compile
./lab2                # segment addresses
```

## Summary of Results

- **Lab 1:** `char` 1, `int` 4, `float` 4, `double` 8, `long` 8, pointer 8, `unsigned int` 4, `long long` 8 bytes. These match the 64-bit column, so the system is 64-bit.
- **Lab 2:** the stack had the highest address (`0x7fff2c3f9364`), the heap was in the middle (`0x5e4545a1f010`), and Data (`0x5e45123bb010`) and BSS (`0x5e45123bb018`) had the lowest and sat next to each other.
- The stack-heap difference was **37082321757012 bytes** (`0x21b9e69da354`).
- Addresses change on each run because of ASLR, but the order of the segments stays the same.

## Environment

- Ubuntu on WSL
- GNU nano 8.7.1
- GCC (Ubuntu)
