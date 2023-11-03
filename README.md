# Simple Shell

## What the code is about:
It is a simple shell

## What is a Shell?
A Shell is a program that takes the command from the user through the standsrd input, the keyboard, and passes them along to the machine to execute them through the kernel.

## How does a shell work?
Basically, a shell performs four main tasks:Read, parse, execute and loop (RPEL).
In performing any of its tasks, a shell can function in either interactive way, or non-interactive way. The **interactive mode** is where the user types inbsome commandwhile the shell wait to recieve, process and execute these commands. On the other hand, the **non-interactive mode** is a way a user wants the shell to perform action using bash script or run a program through an automated process.

### Basic Shell Commands
The basic commands in shell are the following: `ls`, `cd`, `pwd` and `echo`

### List of allowed functions and system calls

+ `access` (man 2 access)
+ `chdir` (man 2 chdir)
+ `close` (man 2 close)
+ `closedir` (man 3 closedir)
+ `execve` (man 2 execve)
+ `exit` (man 3 exit)
+ `_exit` (man 2 _exit)
+ `fflush` (man 3 fflush)
+ `fork` (man 2 fork)
+ `free` (man 3 free)
+ `getcwd` (man 3 getcwd)
+ `getline` (man 3 getline)
+ `getpid` (man 2 getpid)
+ `isatty` (man 3 isatty)
+ `kill` (man 2 kill)
+ `malloc` (man 3 malloc)
+ `open` (man 2 open)
+ `opendir` (man 3 opendir)
+ `perror` (man 3 perror)
+ `read` (man 2 read)
+ `readdir` (man 3 readdir)
+ `signal` (man 2 signal)
+ `stat` (__xstat) (man 2 stat)
+ `lstat` (__lxstat) (man 2 lstat)
+ `fstat` (__fxstat) (man 2 fstat)
+ `strtok` (man 3 strtok)
+ `wait` (man 2 wait)
+ `waitpid` (man 2 waitpid)
+ `wait3` (man 2 wait3)
+ `wait4` (man 2 wait4)
+ `write` (man 2 write)

### Compilation
The shell will be compiled with:

``` C
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Testing
The shell should work like this in interactive mode:

``` C
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:

``` C
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
