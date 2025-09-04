# LibASM

First project after the common core completion. It is a first at ASM_x64 development.

## Requirements

 - nasm
 - ld
 - make

 ## Run

```bash
make #[all|libasm]
```

this command is used to build the `libasm.a` static library

```bash
make exec
```

this one is used to compile the archive like the previous one but it also compiles the `.c` files to make an executables that will run some tests one the library

```bash
./libasm
```

## Other commands

 - `make clean` will clean the `obj/` directory
 - `make fclean` will clean the `obj/` AND the `libasm.a` library directory
 - `make re` will run the `fclean` command and then the `all` rule
 - `make re_exec` will run the `fclean` command and the the `exec` rule
