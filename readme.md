# LibASM

First project after the common core completion. It is a first at ASM_x64 development.

## Requirements

 - nasm
 - ld
 - make

 ## Setup

```bash
make #[all|libasm]
```

this command is used to build the `libasm.a` static library

```bash
make exec
```

this one is used to compile the archive like the previous one but it also compiles the `.c` files to make an executables that will run some tests one the library
