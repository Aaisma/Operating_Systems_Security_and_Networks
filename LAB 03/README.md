# LAB 03: Investigating Process Lifecycles and OS Interaction

## Introduction

This lab looks at what happens after a C program is compiled: how the operating system creates a process, gives it an identity, tracks it while it runs, and receives an exit status when it ends. Five short C programs were written on Ubuntu (WSL) and inspected using `ps` and `echo $?`. All work is inside a folder called `LAB 03`.

## Objectives

1. Observe a running program as a live process using `ps`, `ps aux`, and `grep`.
2. Identify a process's PID and its parent's PPID.
3. Return exit codes from `main()` and read them with `echo $?`.
4. Use standard input and output streams with `scanf()` and `printf()`.
5. Control program flow and termination with conditions and exit codes.

## Programs

- **Task 1** (`task1/task1_alive.c`): Prints "I am starting....", sleeps for 30 seconds, then prints "I am finished."
- **Task 2** (`task2/task2_identity.c`): Prints its own PID and PPID using `getpid()` and `getppid()`, then sleeps for 20 seconds.
- **Task 3** (`task3/task3_exit.c`): Reads a number; prints "Success!" and returns 0 if positive, otherwise "Failure!" and returns 1.
- **Task 4** (`task4/task4_input.c`): Reads a name with `scanf()` and prints a greeting.
- **Task 5** (`task5/task5_control.c`): Prints its PID and asks whether to continue; 1 continues (exit 0), 0 exits (exit 1).

## Commands Used

Process:
- `ps`: Show processes for the current shell
- `ps aux`: Show all processes with user, PID, CPU, and memory
- `ps aux | grep task_alive`: Filter the list to one program
- `ps -p <PID> -o pid,ppid,cmd`: Show PID, PPID, and command for one process

Compile and run:
- `gcc file.c -o name`: Compile source into an executable
- `./name`: Run the program

Exit status:
- `echo $?`: Print the exit status of the last program

## Useful Commands

```bash
gcc task1_alive.c -o task_alive      # compile
./task_alive                         # Terminal 2: run
ps aux | grep task_alive             # Terminal 1: confirm it is running
ps -p 1474 -o pid,ppid,cmd           # check PID and PPID
echo $?                              # exit status (0 = success)
```

## Summary of Results

- `task_alive` appeared in `ps aux` while running, confirming it is a live process.
- `task2_identity` printed PID **1474** and PPID **323**; `ps -p` confirmed the parent is the shell.
- `task3_exit` returned **0** for input `3` and **1** for input `-3`.
- `task4_input` greeted the user by name using standard input and output.
- `task5_control` returned **0** when the answer was 1 and **1** when it was 0.

## Environment

- Ubuntu on WSL
- GNU nano 8.7.1
- GCC (Ubuntu)
