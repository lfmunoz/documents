---
title: GDB
mathjax: true
layout: default
toc: true
---

# GDB 

 GDB is a debugger. GDB is an interactive tool.

Install gdb and ddd


when you compile make sure you use the -g option.
The -g option tells the compiler to save the symbol table—that is, the list of memory addresses corresponding to your
program’s variables and lines of code—within the generated executable.

```bash
gcc -g program.c -o programname
nasm -f elf64 -g -F stabs file.asm
gcc -g main.c

gdb ./a.out
ddd ./a.out
```




# Commands


```

# Add break point
b main
b functionName # better to use function name if code changes
break 16  
break main.c:8
b 16

# adding conditions on break points
condition 1 num_y == 1 # for breakpoint 1 only stop when num_y ==1 
break 30 if  num_y == 1 # combine break and condition



# only stays in effect until the first time line is reached
tbreak

# Remove break point
clear 16

# List all break points
info break 


#Single-stepping

# Go to next line not entering function call
next 
n # don't step into functions

# Run the next line of the program
step 
s
s N  # run the next N lines of the program

# Run program until a breakpiont or error
run 
r
r arg1 arg
r < file1

#  Resume execution until next breakpoint
continue
c

# Run until current fucntion is finished 
f

# inspect variable
# j is a local variable at break point
print j
p var # print current value of variable "var"
p/x y # print in hex
p/c y # print char
p/s y  # print string


# Quick GDB
q

#watchpoint combines the notation of breakpoint and     variable inspection
# instructs the debugger to pause execution of the pogram whenever the value
# of a specified variable changes

watch z
watch (z > 28)

#
frame 1 # previous frame
frame 0 # current fram

up # takes you to previous frame
down # takes you next frame

backtrace # will show entire stack



breakpoint command lists
Wouldn’t it be nice if GDB were to automatically perform a set of commands
each time it reaches a breakpoint?

printf basically works the same way in GDB as
it does in C, but the parentheses are optional.

commands breakpoint-number
...
commands
...
end


commands 1
silent
printf "fibonacci was passed %d.\n", n
continue
end



define print_and_go
printf $arg0, $arg1
continue
end

commands 1
silent
print_ang_go "fib was passeed %d\n" n
end

show user # show all the macros


# tells gdb to automatically print the specifieditem each time there is a pause in execution
display
dsp

call printtree(root)

# get a quick review of the structure of a class or struct
ptype node



# examine memory
x

```


# Command line 

```bash
 gdb -ex 'break fun1' -ex 'break fun2' -ex 'break fun3' ./myprog
 gdb -ex 'break main' -ex 'info b' -ex 'set print pretty on' ./myprog
```

# Configuration / Automation


GDB’s startup files are named .gdbinit by default (gdb executes file .gdbinit after running).
You can have one in your home directory for general purposes and another in the directory
containing a particular project for purposes specific to that project.


```bash
# Example .gdbinit
set pagination off
set logging file gdb.txt
set logging on
file a.out
b f
commands
bt
continue
end
info breakpoints
r
set logging off
quit
```


```bash
# run gdb on x first reading in commands from file z
gdb -command=z x
```





# Errors

**Segmentation faults** occur when a running program attempts to access memory that it does not have permission
to access. Typically the cause is an out-of-bounds array index or an errant pointer value.





# References

* GDB Internals Documentation
* https://sourceware.org/gdb/wiki/Internals


* GDB Documentation
* https://sourceware.org/gdb/current/onlinedocs/gdb.html#File-Options