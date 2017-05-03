<!--

<style>
  .bottom-three {
     margin-bottom: 3cm;
  }
</style>

-->

Mock Exam - CIS342 2017 Spring
===

Basic bash commands
---

1. Which command can be used to find out how a specific command works, including its arguments?
    - A. `help`
    - B. `man`
    - C. `where`
    - D. `which` 

Answer: B. The "man" command is used to find out how to use a command.

2. What permissions does the following command assigns to file "foo"? `chmod 756 foo`

Answer: 756 translates to 111 101 110, meaning the full (read, write, and execute) permissions for user, read and execute permissions for group, and read and write permissions for all other people.

3. Write a command to give `rw-rwx--x` permissions to file "foo".

Answer: the given permissions translate to 671. This can be done using `chmod 671 foo`. <p/>

Script
---

1. Write a bash script to get 2 integers as parameters and print "Ok" if the first parameter is larger that the second one.

Answer: 

```
#!/bin/bash
if [ $1 -lt $2 ]; then
	echo Ok
fi
```

<p/>

1. What should you do to have access to a variable in all consoles?

Answer: Use `export` command to make it an environment variable.<p/>
1. Write a bash script to get a path to a directory as parameter and copy all the files inside it to the user's home directory. 
    - Hint: Symbol `~` refers to home director.

Answer: 

```
#!/bin/bash
cp -r $1 ~
```
<p/>

Advanced bash commands
---

1. Consider running grep with `^[1-5].[7-9]` regular expression. Which of the following matches? Select all that apply:
    - A. 12345
    - B. 56789
    - C. 87761 2889
    - D. 777771827
    - E. 2871765
    - F. 119991
1. Write a command to find all lines of all files under user's home directory recursively that contain a single digit between 5-7 in their names. Ex: file51 matches but file12 does not.

Answer: `find ~ -name "*[5-7]*"`
1. You want to list all the files under the root directory but the output is too long and does not fit into your terminal. How do you handle this?
Answer: 
Use the `more` command. `ls / | more`
<p/>
1. Write a bash script to get the name of a process (Ex. firefox) and print out the pid for it.
Answer: 

```
#!/bin/bash
ps aux | grep $1
```

<p/>
1. You are using vim for editing a file. How can you go back to the console without the need to save the file and close vim?
Answer: press Ctrl+Z keys.<p/>
1. Write a bash script named "mymv" that does the same thing as command "mv". You should not use "mv" in your script.

Answer: 

```
#!/bin/bash
cp $1 $2
rm $1
```
<p/>
1. Use "wc" and "ps aux" commands to print number of current running processes.
Answer: ```ps aux | wc -l```<p/>

GCC, Makefile and GDB
---

1. In the compilation process, describe the job of a linker?
Answer: it merges the object files into a single executable file.<p/>
1. What is the difference between `next` and `continue` commands in gdb?
Answer: `next` goes to the next line but `continue` goes to the next breakpoint.<p/>
1. Write the following compilation stages in correct order: linking, preprocessing, assembling, compilation
Answer: preprocessing->compilation->assembling->linking<p/>
1. Write a makefile with two targets. One for compiling foo.c to binary foo.out linking a library file with name "libbar.a". Another target for removing the compiled binary files and cleaning up.
Answer: 
`gcc -o foo.out foo.c -L. -lbar`
<p/>

C and Assembly
---

1. Given a C program file `hello.c`, write down the commands that convert the file to the following: 1) an assembly file `hello.s`, 2) a relocatable object file  `hello.o`, 3) an executable object file `a.out`.
Answer: 

- 1) `gcc -S hello.c`
- 2) `gcc -c hello.c`
- 3) `gcc hello.c`

<p/>

1. Where is global variable defined?
    - A. outside any function
    - B. inside main function
    - C. inside a function that is not main.
1. Write down the gdb command to examine stack?
Answer: `bt` or `backtrace`<p/>
1. [True/False] CPU has a register pointing to the memory location of the instruction currently being executed.

True

1. [True/False] CPU supports instructions to move data from memory.

True

1. How do you allocate memory space to store exactly 3 integers. What happens if we copy more integers to the allocated memory?


Answer:
`int a=malloc(sizeof(int)*3);`

Error: Segmentation fault

<p/>
1. What error does the following program generate? Why?

```c    
    #include<stdio.h>
    #include<stdlib.h> 
    int main()
    {
         int *ptr;
         *ptr = 10;
         printf("%d\n",*ptr);
         return 0;
    }
```

Answer: This may cause segmentation fault. Because the program access to low memory address `10` which is (usually in kernel space) and is inaccessible to user-space program.<p/>
