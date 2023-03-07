# About
A stack based machine code simulator written in C

It only supports simple commands, as my purprose here was to learn how to deal with file reading in C, I think there's no need for it to get more complex than this.

## Commands
| Controls | Usage 
|----------|:---------
| **push [num]** | Push a number on to the stack
| **pop** | Pop off the first number on the stack
| **add** | Pop off the top 2 items on the stack and push their sum on to the stack
| **ifeq [address]** | Examine the top of the stack, if it's 0, continue, else, jump to [address] where [address] is a line number
| **jump [address]** | Jump to a line number
| **print** | Print the value at the top of the stack
| **dup** | Push a copy of what's at the top of the stack back onto the stack

## Compiling
Just clone the repository and on the folder run
```console
make
```
The generated binary file will be in /bin.

The Makefile makes use of GCC, but you can change for you compiler of choice if you want.
