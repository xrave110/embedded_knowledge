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

- [Embedded knowledge](#embedded-knowledge)
  - [Table of content](#table-of-content)
  - [1. Structure padding](#1-structure-padding)
  - [2. Buggy](#2-buggy)
  - [3. Volatile and threads](#3-volatile-and-threads)
    - [Thread vs process](#thread-vs-process)
    - [Threads](#threads)
    - [Volatile](#volatile)
      - [Variations](#variations)
  - [4. Sorting algorithms](#4-sorting-algorithms)
    - [Typical sorting algorithms](#typical-sorting-algorithms)
    - [Advanced sorting algorithms](#advanced-sorting-algorithms)
  - [5. Algorithms for sorted data](#5-algorithms-for-sorted-data)
  - [6. Data structures](#6-data-structures)
    - [Hashing data structure](#hashing-data-structure)
    - [Linked list](#linked-list)
    - [Trie Data Structure](#trie-data-structure)
  - [7. Bitwise](#7-bitwise)
  - [8. CMake](#8-cmake)

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

#### Variations
- `volatile int* done;` - pointer to volatile variable
- `int *volatile done;` - volatile pointer to variable
- `volatile int *volatile done;` - volatile pointer to volatile variable

Compiler optimizations - makes the code faster and more efficient that is why it is not recommended to overuse volatile.

An object marked as `const volatile` will not be permitted to be changed by the code (an error will be raised due to the const qualifier) - at least through that particular name/pointer.

The volatile part of the qualifier means that the compiler cannot optimize or reorder access to the object.

In an embedded system, this is typically used to access hardware registers that can be read and are updated by the hardware, but make no sense to write to (or might be an error to write to).
Example:
```C
unsigned int const volatile *status_reg; // assume these are assigned to point to the 
unsigned char const volatile *recv_reg;  //   correct hardware addresses


#define UART_CHAR_READY 0x00000001

int get_next_char()
{
    while ((*status_reg & UART_CHAR_READY) == 0) {
        // do nothing but spin
    }

    return *recv_reg;
}
```

If these pointers were not marked as being volatile, a couple problems might occur:
  - the while loop test might read the status register only once, since the compiler could assume that whatever it pointed to would never change (there's nothing in the while loop test or loop itself that could change it). If you entered the function when there was no character waiting in UART hardware, you might end up in an infinite loop that never stopped even when a character was received.
  - the read of the receive register could be moved by the compiler to before the while loop - again because there's nothing in the function that indicates that *recv_reg is changed by the loop, there's no reason it can't be read before entering the loop.

## 4. Sorting algorithms
### Typical sorting algorithms
- Bubble sort - Time complexity: O(n)/O(n^2) - Space complexity: O(1)
- Selection sort - Time complexity: O(n^2) - Space complexity: O(1)
- Insertion sort - Time complexity: O(n^2) - Space complexity: O(1)
- Merge sort - Time complexity: O(nlog(n)) - Space complexity: O(n)
- Quick sort
- [source code](./sorting_algorithms/types_of_sorting.cpp)
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

## 7. Bitwise

## 8. CMake


