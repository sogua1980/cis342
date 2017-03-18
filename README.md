% Lecture notes in CIS342 
% Yuzhe Tang, Amin Fallahi
% Spring, 2017

Section 1: Bash
===

References
---

- "Advanced Bash-Scripting Guide" [[web](http://www.tldp.org/LDP/abs/html/)]

Editor
---

- For Unbuntu/Linux novice, recommend `gedit`. To launch the editor:
    - `gedit filename &`
- For advanced user, recommend `vim`

Basic commands
===

---

- `man commandname`
- `echo`,`cat`,`more`
- environment variables
    - `echo $PATH`,`echo $PWD`
    - `printenv`
    - `export`

File management
---

- basic commands
    - `touch`, `mv`, `rm`
    - `mkdir, `ls`
    - `pwd`
- `chmod`: permission bits
    - `u`,`g`,`o`,`a`,`x`,`w`,`r`,`+`,`-`,`=`
    - umask
- `ln`: symbolic/hard link


<!--

Homework 2
---

Write down commands to do the following: 

1. can you use "rm" instead of "rmdir" to remove an empty directory? what parameters do you need to make it work?
2. what permissions are needed for a user to be able to change the name of a directory?
3. create directory with name 'dir_cis342'
4. copy all the files in the current directory that are c programs (their name ends with .c) to 'dir_cis342'
5. create symbolic links to 'dir_cis342'? (verify your link is working, by `cd` your link).

-->

Shell programming (Feb. w3)
===

Introduction
---

- Why learn shell programming?
    - automate administrative tasks, save your efforts!
    - e.g. automatic software update, file backup, resource monitoring
- Script: tie shell commands in a file 
- Execute script `script.sh`:
    - `./script.sh`
    - `source script.sh`

Basics: Shell language
---

- `#!` sha-bang is a two-byte magic number that designates a file type
    - basically says it's an executable shell script 
- Language syntax: if/else, variable
- demo:
    1. `#!/bin/bash echo 'hello world';`
    2. `#!/bin/bash a=1;b=2;a=$a+$b;echo $a;`
    2. `#!/bin/bash a=1;b=2; a=$((a+b));echo $a;`
    3. `if [ $a -gt $b ];then echo 'a larger than b';fi`

---

- exercise:
    1. \* try `a=1;b=2;c=$a;a=$b;b=$c;echo $a,$b;`, and put the output to the **blackboard**.
    2. write a script to initialize variables `a`, `b`, `c` and print their sum.
    3. write a script to swap the names of two files, file1 and file2. For example if input file1 contains Alice and file2 contains Bob at the beginning, after the execution, file1 should contain Bob and file2 should contain Alice.

Passing arguments
---

- demo: 
    - `#!/bin/bash echo $1; echo $2; echo $#;`
- exercise:
    1. `#!/bin/bash a=$1; b=$2; echo $((a*b));`; try this script and tell what it does?
    1. write a script to get 3 integers from the command-line and prints their product.
        - what happens if you do not pass the 3 required integers when executing the bash script?

Commenting
---

- `#` is used to comment in bash

<!--
Exit values 
---

- intro:
    - executing every command has a "result" or exit value.
- demo: 
    - `echo alice; echo $?; rm filenamedttt; echo $?`
- exercise: 
    1. `touch file111; rm file111; echo $?` what is the output? 
    2. how do you modify the above script so that it prints 1
    3. write a script by using `touch` and exit value to test if a file (with name `AAA`) exist?
-->

<!--

Homework 3
---

1. `mkdir fff; echo $?; mkdir fff; echo $?;` why is output different?
2. can exit code have any other value that 0 and 1? read the man page for "exit". 
    - write a program that gets 3 integers and prints the sum of them. Test the exit code when the number of arguments provided are not valid (<>3).
3. we want to use the rm command but we don't want to get errors. Write a script to get a file name as a parameter and removes it. If the file does not exist, it should not give an error.

-->


Grep & Find (Feb. w4)
===

Introduction
---

- A classic matching problem: 
    - takes as input a string and "pattern", outputs a binary decision.
    - `match(al.*ce,alice)=1`
- Format of the pattern: **regular expression** (regex).
- Relevance to Linux shell: `grep`, search in `vim`

Regular expression & grep
---

1. asterisk `*`
    - `match(1133*,113)=1`
    - demo: `echo 113 | grep 1133*`
    - `grep(p,s)` finds *all* substrings in `s` that match pattern `p`
2. dot `.`
    - `match(13.,13)=0`
    - `match(13.,134)=1`
5. Brackets `[...]`: enclose a set of characters 
    - `match(1[345],13)=1`, `match(1[345],15)=1`, `match(1[345],18)=0`
    - `match(1[3-5],14)=1`
    - `match(1[^3-5],14)=0`,`match(1[^3-5],18)=1`

---

3. caret `^`: beginning of a line
4. dollar sign `$`: end of a line
    - `^$` matches blank lines.
<!--    - backslash `\\`: `\$`-->

Grep
---

- Demos
    1. `grep hello hello.c`
    2. `grep -r hello .`
    3. `grep -i HELLO hello.c`

---

- Exercise:
    1. Given a file `file1` with `hello too`, try following commands, and report the result
        - `grep ^hello file1`
        - `grep hello$ file1`
        - `grep t[wo]o file1`
        - `grep ^[A-Z] file1`
    2. Write a command to find all lines of all files under current directory recursively that contain a single word "hello".

Find
---

- Intro
    - `find` searches files, while `grep` searches text
    - note: `find` name matching is *parameter expansion*, not regex.
- demo:
    1. `find . -name "*.c"` #
    2. `find / -maxdepth 1 -type d`
- exercise:
    4. write a command to find all the files with name starting with `fil` under the current directory.

<!--

Homework
---

1. There are a couple of other commands like "find". Test these and describe the difference: "which", "whereis", "locate".
2. Search the internet for "grep regular expression for US phone numbers" and find a regular expression for finding all file lines that contain a valid US phone number. Test it on a sample file and write the command. Examples of valid US phone number formats: (315)1234567, 680-123-4567, 7161234567, (585) 1234567, (800)123-4567
3. Modify the regular expression you used in the previous question to only match Syrause area codes (315 and 680)
4. Write a regular expression to match all lines of a file which contain an email address. You can search the internet for this. But make sure that it works!
5. Modify the regular expression you used in the previous question to only match syr.edu emails.
6. What option of the find command do you use for finding all files with a certain permission?
7. Use -type option of find command to find all "directories" in the home directory of a user named "foo" recursively.
8. Use find command with -regex option to find all files that their names starts with a lowercase letter.

-->

Command execution and processes (Mar. w1)
===

Redirection
---

- Intro: redirect from one file to another
    - standard printout `stdout` is a file, 
    - `stderr` is another file
    - ampersand `&`: both `stderr` and `stdout`
- demo:
    1. `echo 'hello Alice' > somefile`
    2. `echo 'hello Alice' >> somefile`
    3. `rm nonexistfile > somefile`
    4. `rm nonexistfile 1>somefile`, `rm nonexistfile 2>somefile`, `rm nonexistfile &>somefile`

---

- exercise:
    1. try `pwd > ZZZ`; explain what this command does?
    2. write a command to store the list of files in current directory to a file named by 'f'

Process management [opt]
---

- `top` (global), `jobs` (children processes)
- `ps`: (default) all processes that have controlling terminals
    - `ps aux`: global
    
Pipe (IPC1)
---

- Chaining multiple commands 
    - commands run in processes; a process has descriptors or channels to files
    - connect the `stdout` descriptor of a previous command to the `stdin` of the current command. (like a pipe)
    - A pipe is a method of interprocess communication (IPC)
- demo:
    1. `ls /etc | more`
    2. `ls /etc | vim -`
    3. `pwd | ls`

---

- exercise:
    1. run command `ls /etc | grep conf$ > output`; explain what it does.
    2. design a command to output all files with `cis` in their name, using pipe. Note you can't use `find`.
        - hint: use `ls` and `grep`
    
Signals & background processes (IPC2)
---

- foreground/background: 
    - multiple processes contend for a file
    - a process runs in background/foreground
    1. demo: run in foreground: `gedit`, `vim`
    2. demo: run in background: `gedit &`, `vim &`
- signals:
    - `<CTRL+Z>`: (keyboard) sends pause signal to the process in foreground
    - `<CTRL+C>`: (keyboard) sends quit signal to the process in foreground
    3. `<CTRL+C>`, `<CTRL+Z>`, `fg`
    4. demo: `jobs`, `fg 1`: switch between multiple background processes

----

- exercise:
    1. run `top`. now use `<ctrl+c>` to terminate it. run in another time and this time use `<ctrl+z>`. what is the difference?
    2. run `vim f1` in the background. also run `vim f2` in the background. try switching between them in one terminal.

Execution mode [opt]
---

- launch a new process: `./script script.sh`, `command`
- run in current process: `source script.sh`, `. script.sh`

C Programming Language
===

Program structure
---

- Demo:
    - ``#include <stdio.h>
int main()
{
    printf( "Hello World!\n" );
    return 0;
}``
    - Compiling using GCC: ``gcc hello.c``
    - Using variables: ``int a;``
    - Printing an integer variable: ``printf("%d",a);``
    - Getting integer input from user: ``scanf("%d",&a);`` 
    - Assigning value to a variable: ``a=2017;``
- Exercise:
    - Write a program to get 2 integers from the user and print the sum of them
    - Try printing integers and text together: ``int a; a=2017; printf("March %d",a);``
    - Try ``a++;``, ``a*=5;``
    - Write a program to swap the value of two integer variables
    
Conditional Statements
---

- Demo:
    - ``c
#include <stdio.h>	

int main()
{
    int age;
    printf( "Please enter your age" );
    scanf( "%d", &age );
    if ( age &lt; 100 ) {
``

<!--

Command execution model
---

- executing a command in a process
- a process has "channels" or "file descriptors" that binds to "files"
     - `stdout`, `stderr`
     - `stdin`
     - files: devices (keyboard, display), on-disk files
- multiple processes contend for a file
    - a process runs in background/foreground
    - `fg`, `<CTRL+Z>`, `jobs`
    
-->

<!--

Homework 4
---

1. Redirect *all* the printout of command `(echo t; rm ttt)` to a file of name `f`. Hint `(A; B)` means executing two commands `A` and `B` in sequence (without piping). 
2. Print all the processes in the system with name `bash`; hint: `ps aux` is the command to print all the processes in the system.
3. When running two commands `top &`, `vim f &` in the background, how will you bring the `vim` command to the screen. Describe the command you will use and the command-line argument.
4. `wc f` is a command that prints the word count in file `f`. In particular, `wc -l f` prints the number of lines in file `f`. Using `ls` and `wc` commands, write a piped command to print out the number of files in the current directory.

-->

<!--

Processes
===

top
---

- demo: `top`
- exercise:
    1. open firefox and use top interactive commands to close it
    2. open firefox again. open some websites and tabs and see how they affect the values in top command.

ps and kill
---

- demo:
    1. `ps aux`
    2. `kill -15 1234`
    3. `kill -l`
- exercise:
    1. use grep to find all the processes running as root
    2. open firefox web browser and find its pid
    3. terminate firefox using the kill command. Suppose firefox is crashed and you can't close it using graphical interface. What you need to do to close it?

-->
