# LAB 04.1: Auditing of Text and Initialized Data Segments via Hardware Disassembly

## Introduction

This lab looks at how a compiled C program is laid out in memory. The program `demo2.c` is built with debug symbols and run inside GDB on Ubuntu (WSL). Addresses and section ranges are checked to confirm where the function, the string literal and the global variable are stored. All work is in a folder called `LAB 4.1`.

## Objectives

1. Compile `demo2.c` with `-g` and start it in GDB.
2. Set a breakpoint and record the runtime addresses of the function, string literal and global variable.
3. Use `info files` to find the start and end address of `.text`, `.rodata`, `.data` and `.bss`.
4. Check that each item falls inside the correct section.
5. Read raw memory with `x` and find the byte order (endianness).
6. Answer the verification and post-lab questions.

## Programs

- **`demo2.c`** (`LAB 4.1/demo2.c`): Prints the addresses of an initialized global (`data_global_var = 0x12345678`), a string literal (`text_string_literal`) and a function (`check_execution`), then stops at line 23 for inspection in GDB.

## Memory Segments

- **Text (`.text`):** Machine code, read-only (`check_execution`).
- **Rodata (`.rodata`):** Read-only constants such as string literals (`"Text_Segment_Verification"`).
- **Data (`.data`):** Initialized globals (`data_global_var` and the `text_string_literal` pointer).
- **BSS (`.bss`):** Uninitialized globals, placed right after `.data`.

## Commands Used

- `mkdir`, `cd`: Create and enter a folder
- `nano demo2.c`: Write or edit the C file
- `cat -n demo2.c`: View the file with line numbers
- `gcc -g demo2.c -o demo2`: Compile with debug symbols
- `gdb ./demo2`: Run the program in GDB
- `break 22`: Set a breakpoint (GDB moves it to line 23 because line 22 is a comment)
- `run`: Run until the breakpoint
- `info files`: Show the address range of every section
- `print &data_global_var`: Address of the global variable
- `x/wx &data_global_var`: Read one 4-byte word in hex
- `x/4xb &data_global_var`: Read the same 4 bytes one by one (shows byte order)
- `print text_string_literal`: Address and text of the string
- `x/s text_string_literal`: Read the string from memory
- `print &text_string_literal`: Address of the pointer variable itself
- `continue`, `quit`: Finish the program and exit GDB

## Useful Commands

```bash
gcc -g demo2.c -o demo2     # compile with debug symbols
gdb ./demo2                 # start GDB
(gdb) break 22
(gdb) run
(gdb) info files            # section address ranges
(gdb) print &data_global_var
(gdb) x/wx &data_global_var
(gdb) print text_string_literal
(gdb) x/s text_string_literal
(gdb) print &text_string_literal
(gdb) continue
(gdb) quit
```

## Summary of Results

- The file type is `elf64-x86-64`, so the system is 64-bit x86-64. Addresses are 8 bytes wide. Entry point: `0x555555555080`.
- Runtime addresses: `data_global_var` at `0x555555558010`, string literal at `0x555555556008`, `check_execution` at `0x555555555169`, and the pointer variable `text_string_literal` at `0x555555558018`.
- Section ranges: `.text` `0x555555555080` to `0x55555555520f`, `.rodata` `0x555555556000` to `0x5555555560f0`, `.data` `0x555555558000` to `0x555555558020`, `.bss` `0x555555558020` to `0x555555558028`.
- Each item falls inside the expected section. `.text` is at a lower address than `.data`, and `.data` is below `.bss`.
- The breakpoint on line 22 was placed at line 23 because line 22 is a comment with no machine code.
- `print text_string_literal` shows the string address in `.rodata`, while `print &text_string_literal` shows the pointer's own address in `.data`. The pointer sits right after the 4-byte `data_global_var` plus 4 bytes of padding for 8-byte alignment.
- The value `0x12345678` is stored as `78 56 34 12`, so the system is **Little-Endian**.
- `.text` and `.rodata` are kept on separate pages because `.text` is read + execute while `.rodata` is read only. This allows NX protection and keeps constants out of the instruction cache.
- Addresses start with `0x5555...` because the binary is PIE. Under GDB, ASLR is off, so they stay the same between runs.

## Environment

- Ubuntu on WSL
- GNU gdb 17.1 (Ubuntu 17.1-2ubuntu1)
- GCC (Ubuntu)
- GNU nano 8.7.1
