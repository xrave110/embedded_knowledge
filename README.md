# Embedded knowledge

Bunch of examples which reminds some important embedded concepts.
Installation (linux):
`sudo apt install clang`

Compilation:
`clang <fileName>.c`

Run:
`./ <fileName>.c`

## Table of content

[Structure padding](#structure-padding)


## 1. Structure padding
- Usually to have most efficient padding you must segregate the structure from the biggest data type to the smallest.
- It is also possible to use compiler `pragma pack(1)` to padd correctly but it requires more computation power.
- The issue are showed in the <a src='./struct_padding.c'>source code</a>.