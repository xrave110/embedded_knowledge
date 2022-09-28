# Embedded knowledge

Bunch of examples which reminds some important embedded concepts.

Installation (linux):

`sudo apt install clang`

Compilation:

`clang <fileName>.c`

Run:

`./ <fileName>.c`

Or use gcc.
## Table of content

[Structure padding](#1.-structure-padding)
[Buggy](#2.-buggy)
[Sorting algorithms](#3.-sorting-algorithms)
- [Typical sorting algorithms](#typical-sorting-algorithms)
[Algorithms for sorted data](#4.-algorithms-for-sorted-data)
- [Two pointers technique](#two-pointers-technique)
- [Binary search](#binary-search)
[Data Structures](#5.-data-structures)
- [Hashing Data Structure](#hashing-data-structure)
- [Linked List](#linked-list)


## 1. Structure padding
- Usually to have most efficient padding you must segregate the structure from the biggest data type to the smallest.
- It is also possible to use compiler `pragma pack(1)` to padd correctly but it requires more computation power.
- The issues are showed in the [source code](./struct_padding/struct_padding.c).

## 2. Buggy
- gdb debbuger simple usage
- simple makefile with clang
- buggy code with null pointer to be debugged
- issue with using printf as a debugger
- [source code](./buggy/buggy.c)

- GDP debugging:
    - bt - backtrace 
    - up - go up the stack
    - p - print variable

    ```shell
    (gdb) run
    Starting program: /home/anything/Embedded/embedded_knowledge/buggy/buggy.o 

    Program received signal SIGSEGV, Segmentation fault.
    __strcpy_avx2 () at ../sysdeps/x86_64/multiarch/strcpy-avx2.S:301
    301     ../sysdeps/x86_64/multiarch/strcpy-avx2.S: No such file or directory.
    (gdb) bt
    #0  __strcpy_avx2 () at ../sysdeps/x86_64/multiarch/strcpy-avx2.S:301
    #1  0x00000000004011c2 in main (argc=1, argv=0x7fffffffdab8) at buggy.c:14
    (gdb) up
    #1  0x00000000004011c2 in main (argc=1, argv=0x7fffffffdab8) at buggy.c:14
    14          strcpy(buffer, argv[WHICH_ARG]);
    (gdb) p buffer
    $1 = 0x4052a0 ""
    (gdb) p arv[WHICH_ARG]
    No symbol "arv" in current context.
    (gdb) p argv[WHICH_ARG]
    No symbol "WHICH_ARG" in current context.
    (gdb) p argv[1]
    $2 = 0x0
    (gdb)
    ```
## 3. Sorting algorithms
### Typical sorting algorithms
- Bubble sort
- Merge sort
- Quick sort
### Advanced sorting algorithms
- Radix sort
- Heap sort
## 4. Algorithms for sorted data
- ### Two pointer technique
  - [source code](./algorithms_sorted/two_pointers_technique.c)
- ### Binary search
  - [source code](./algorithms_sorted/binary_search.c)

## 5. Data structures
### Hashing data structure
### Linked list
