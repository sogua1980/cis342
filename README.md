A. Bash
===

References
---

- "Advanced Bash-Scripting Guide" [[web](http://www.tldp.org/LDP/abs/html/)]

Editor
---

- For Unbuntu/Linux novice, recommend `gedit`. To launch the editor:
    - `gedit filename &`
- For advanced user, recommend `vim`

File management
===

---

- touch, mv, rm
- chmod: permission bits
    - umask
- ln: symbolic/hard link

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
    1. open firefox web browser and find its pid
    2. terminate firefox using the kill command. Suppose firefox is crashed and you can't close it using graphical interface. What you need to do to close it?


Advanced commands
===

Command execution model
---

- a command is run in a process
- a process access "files"
    - file: stdout/stdin, stderr, on-disk files
- processes contend the "frontend" display
- source vs `./`

Redirection
---

- intro: 
    - redirect from one file to another
        - standard printout is a file, 
        - error printout is another file
    - `>`, `>>`
- demo:
    1. `echo 'hello Alice' > somefile`
    2. `echo 'hello Alice' >> somefile`
    3. `rm XXX>somefile`, `rm XXX &>somefile`, 
    4. `rm XXX 1>somefile`, `rm XXX 2>somefile`, 
- exercise:
    1. try `pwd > ZZZ`; explain what this command does?
    2. write a command to store the list of files in current directory to a file named 'YYY'

Pipe
---

- intro:
    - chaining multiple commands
    - pass output (stdout) of a previous command to input (stdin) of the next one.
    - A pipe is a classic method of interprocess communication
    - `|`, `&&`
- demo:
    1. `ls /etc | more`
    2. `pwd | ls`
    3. use grep to find all the processes running as root
- exercise:
    1. can you pipe and redirect more than one time? `ls /etc | more > output`
    2. can you write the error to a file? like `rm nonexistingfile1 2> output`.

background processes
---

- demo:
    1. `vim &`
    2. `jobs`
    3. `fg`
- exercise:
    1. run `top`. now use ctrl+c to terminate it. run in another time and this time use ctrl+z. what is the difference?
    2. run top in the background. also run vim in the background. try switching between them in one terminal.
    3. copy a big file that takes a long time in the background and observe when it finishes with top.
<!--
Homework 4
---

1. read the man page for `head` and `tail` commands. write a bash script to get name of a file and writes the 3 first and 3 last lines of the file to another file named `output`.
2. read the man page for `wc` command. write a bash script to get name of a file and removes it if it contains less that 3 words.
3. using `ls` and `wc` commands, write a single command to print out the number of files in the current directory.
4. use head and tail to print out lines number 25 to 30 of a long file.

-->
