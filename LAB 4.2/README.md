# LAB 04.2: Mapping Process Runtime Topography Using Low-Level Hardware Debugging Infrastructure

## Introduction

This lab looks at how a running process is laid out in virtual memory. The OS gives each process its own private virtual address space, split into regions: uninitialized globals go in `.bss`, local variables live on the stack, and `malloc()` memory comes from the heap. The program `demo.c` is built with debug symbols and paused inside GDB on Ubuntu (WSL). `readelf` is used to compare the static layout of the file with the live layout shown by the kernel. All work is in a folder called `LAB 4.2`.

## Objectives

1. Compile `demo.c` with `-g` and run it in GDB.
2. Find the `.bss` range with `info files` and check that the global variable falls inside it.
3. Compare the file layout (`readelf -l`) with the runtime layout and explain the base address of a PIE.
4. Get the `[heap]` and `[stack]` ranges with `info proc mappings`.
5. Read stack and heap values with `print` and `x`, and explain `x/1wd`.
6. Answer the post-lab questions.

## Programs

- **`demo.c`** (`LAB 4.2/demo.c`): Creates one variable in each memory region and prints their addresses with `%p`, then stops at a breakpoint for inspection in GDB.
  - `bss_global_var`: global with no starting value (`.bss`, defaults to 0)
  - `stack_local_var`: local variable in `main()` with value `42` (stack)
  - `heap_ptr`: pointer to `malloc()` memory holding value `99` (heap)

## Memory Regions

- **BSS (`.bss`):** Uninitialized globals, zeroed at start. Sits right after `.data`.
- **Heap:** Memory from `malloc()`. Grows upward (toward higher addresses).
- **Stack:** Local variables and function frames. Grows downward (toward lower addresses).

## Commands Used

- `mkdir`, `cd`: Create and enter a folder
- `nano demo.c`: Write or edit the C file
- `cat demo.c`: View the file
- `gcc -g demo.c -o demo`: Compile with debug symbols
- `gdb ./demo`: Run the program in GDB
- `break 23`: Set a breakpoint (GDB moves it to line 26, the next line with code)
- `run`: Run until the breakpoint
- `info files`: Show the address range of every section
- `readelf -l demo`: Read the program headers and section-to-segment mapping
- `print &bss_global_var`: Address of the global variable
- `info proc mappings`: Live virtual memory map of the process
- `print stack_local_var`, `print &stack_local_var`: Value and address of the stack variable
- `x/4wx $sp`: Show 4 words of memory from the stack pointer, in hex
- `print heap_ptr`: Address stored in the heap pointer
- `x/1wd heap_ptr`: Show 1 word at that address, in decimal
- `continue`, `quit`: Finish the program and exit GDB

## Useful Commands

```bash
gcc -g demo.c -o demo       # compile with debug symbols
readelf -l demo             # static program headers
gdb ./demo                  # start GDB
(gdb) break 23
(gdb) run
(gdb) info files            # section ranges (.bss)
(gdb) print &bss_global_var
(gdb) info proc mappings    # [heap] and [stack] ranges
(gdb) print stack_local_var
(gdb) print &stack_local_var
(gdb) x/4wx $sp
(gdb) print heap_ptr
(gdb) x/1wd heap_ptr
(gdb) continue
(gdb) quit
```

## Summary of Results

- **Addresses printed by the program:** `bss_global_var` at `0x555555558014`, `stack_local_var` at `0x7fffffffde6c`, `heap_ptr` at `0x555555559010`. BSS and heap start with `0x5555...`, while the stack starts with `0x7fff...`, so the stack sits much higher.
- **Breakpoint:** `break 23` was placed at line 26 because line 23 has no executable code. The pause happens after `malloc()` and before `free()`.
- **`.bss` range (`info files`):** `0x555555558010` to `0x555555558018`. It starts exactly where `.data` ends. `bss_global_var` (`0x555555558014`) is inside it.
- **`readelf -l`:** `.bss` is in segment 05, the RW LOAD segment, with `.init_array`, `.fini_array`, `.dynamic`, `.got` and `.data`. `FileSiz` is `0x278` and `MemSiz` is `0x280`. The extra `0x8` bytes are the `.bss`, which is not stored in the file but is reserved when loaded.
- **Static vs runtime address:** The file address `0x4014` differs from the runtime address `0x555555558014` because the program is a PIE. Base address `0x555555554000` + `0x4014` = `0x555555558014`. The end of `.bss` also matches: `0x555555554000` + `0x4018` = `0x555555558018`.
- **Heap and stack ranges (`info proc mappings`):** `[heap]` is `0x555555559000` to `0x55555557a000` and `[stack]` is `0x7ffffffde000` to `0x7ffffffff000`. `heap_ptr` is inside `[heap]` and `stack_local_var` is inside `[stack]`. Each is `0x21000` bytes (132 KB) in size.
- **Stack values:** `stack_local_var` is `42`. `x/4wx $sp` starts at `0x7fffffffde60` and shows `0x00000000 0x00000000 0x00000000 0x0000002a`. The last word is at `0x7fffffffde6c` and `0x2a` is 42 in hex.
- **Heap value:** `x/1wd heap_ptr` shows `99`.
- **How `x/1wd` works:** `1` is the count (show 1 unit), `w` is the size (one 4-byte word, the size of an int), and `d` is the format (decimal).

## Post-Lab Answers

- **Do the stack and heap move toward each other?** Yes. The heap grows upward, so its end address (`0x55555557a000`) increases. The stack grows downward, so its start address (`0x7ffffffde000`) decreases. The gap is `0x7ffffffde000 - 0x55555557a000 = 0x2AAAAAA64000`. If the heap grows by Δh and the stack by Δs, the new gap is `0x2AAAAAA64000 - Δh - Δs`, which is always smaller.
- **Same addresses in two terminals?** Normally the addresses differ because Linux randomizes the layout (ASLR) on each run. Inside GDB, ASLR is off, so the addresses stay the same. Even if the printed addresses match, the processes do not share memory. Each process has its own virtual address space that the OS maps to different physical RAM, so one program cannot read or change the other's data.

## Environment

- Ubuntu on WSL
- GNU gdb 17.1 (Ubuntu 17.1-2ubuntu1)
- GCC (Ubuntu)
- GNU nano 8.7.1
- readelf (GNU binutils)
