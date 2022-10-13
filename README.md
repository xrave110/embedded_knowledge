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
[Volatile and threads](#3.-volatile-and-threads)
[Sorting algorithms](#4.-sorting-algorithms)
- [Typical sorting algorithms](#typical-sorting-algorithms)
[Algorithms for sorted data](#5.-algorithms-for-sorted-data)
- [Two pointers technique](#two-pointers-technique)
- [Binary search](#binary-search)
[Data Structures](#6.-data-structures)
- [Hashing Data Structure](#hashing-data-structure)
- [Linked List](#linked-list)
- [Trie Data Structure](#trie-data-structure)


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

## 3. Volatile and threads

### Thread vs process
Thread is faster and has sharable resources.
### Threads
- Threads can be created using library `#include <pthread.h>`
- In order to create thread object there is need to define object with a struct type `pthread_t`
- In order to have some function be performed with other thread there is need to use `pthread_create`
- In order to wait until all threads will finish there is need to use `pthread_join`

[source code](./threads_signals_volatile/threads.c)
Run compilation with threads: `clang volatile.c -lpthread`

### Volatile
Volatile keyword prevents from optimalization. It is used when some other process/thread can change specific variable and we do not want to have the variable to be optimized by compiler which is not aware of this process/thread. The compiler will not have any assumptions to this variable.
[source code](./threads_signals_volatile/volatile.c)

Run compilation with optimalization: `clang volatile.c -O2`

#### Variations:
- `volatile int* done;` - pointer to volatile variable
- `int *volatile done;` - volatile pointer to variable
- `volatile int *volatile done;` - volatile pointer to volatile variable

Compiler optimizations - makes the code faster and more efficient that is why it is not recommended to overuse volatile.
## 4. Sorting algorithms
### Typical sorting algorithms
- Bubble sort
- Merge sort
- Quick sort
### Advanced sorting algorithms
- Radix sort
- Heap sort
## 5. Algorithms for sorted data
- ### Two pointer technique
  - [source code](./algorithms_sorted/two_pointers_technique.c)
- ### Binary search
  - [source code](./algorithms_sorted/binary_search.c)

## 6. Data structures
### Hashing data structure
  - array with hash tables
  - ideal time complexity: O(1)
  - external chain solution with list approach

### Linked list
In order to have list there is need to have a node structure which would have two/three arguments as follow:
  - value
  - pointer to next element (if it is a head then pointer should be NULL)
  - the NULL head will allow to easily iterate through the whole list 
  - time complexity: O(n)
  
  - [source code](./linked_listed/list.c)
  

### Trie Data Structure
Data structure used for retrieving string of symbols. Each trie data structure has a root and branches which allow to find, insert and delete special element very fast.
