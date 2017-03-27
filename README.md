% Lecture notes in CIS342 
% Yuzhe Tang, Amin Fallahi
% Spring, 2017

Section 2: Programming in C/C++ 
===

gcc & make (Mar. w4)
===

References
---

- "Unix Programming Tools", [[link](http://cslibrary.stanford.edu/107/UnixProgrammingTools.pdf)]
- Computer Systems: A Programmer's Perspective, Randal E. Bryant and David R. O'Hallaron, Chapter 1, [[online pdf](http://csapp.cs.cmu.edu/2e/ch1-preview.pdf)]

- Source files: [[src directory](./marw4)]

Compilation overview
---

- Two steps of compilation:
    - *compiling*: text `.c` file to  relocatable `.o` (object) file
    - *linking*: multiple relocatable `.o` files to one executable `.o` file
        - *symbol*: reference to link construct (declaration) in one `.o` file to construct (definition) in another `.o` file

---

![Linker](./images/link.png)

<!--
![Linker](/Users/tristartom/workspace/teaching/cis342/cis342/images/link.png)
-->


C: basics
---

```c
#include <stdio.h> //preprocessor
int y = 3; //global var. (def. & init.)
//extern int y; //global var. (dec.)
int main() //function (def.)
{
    int x = 0; //local var. (def. & init.), literal, 
    printf("y = %d\n",y); //function (invocation)
    return 0;
}
```

Life of a C construct
---

| | variable | function 
| --- | --- | --- |
| declaration | `extern int x;` | `void foo();`
| definition | `int x;` | `void foo(){}`
| initialization | `int x = 6;`
| assignment | `x = 1;`
| reference | `y = x;` | `foo();` (invocation)
| destroy

Gcc: Flags
---

- `-c` for compile, `-o` for output; demo
- `-Wall`, w for warning; demo 
- `-I` for `#include`; demo
    - header file (storing declarations)
- `-Ldir`/`-lmylib` for library to link
    - search library for unsolved symbols (functions, global variables) when linking
- `-g` for debug (later)
- ref [[link](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html#Option-Summary)]

<!-- 

Advanced topics on GCC
---

Compiler process

| compilation step | | main flag | secondary flags |
| --- | --- | ---  | --- |
| preprocessor | `.c`->`.i` | | `-I./includes` (rpath) 
| compiling | `.i`->`.o` | `gcc -c` |
| assembler | `.s`->`.o`(relocatable) | `gcc -s` |
| linker | `.o`(relocatable),`.a`->`.o`(executable) | (no flag) | `-L. -lx`, `-Wl,` |
 
* `-Wl,option` Pass `option` to the linker. For example, `-Wl,-Map,output.map` passes `-Map output.map` to the linker.
- `-L`
    - gcc flag `-L/home/lib` is equal to environment var `export LIBRARY_PATH=/home/lib`
- `gcc A B`: it compiles B first then A.

-->

make
---

```
all: link
\t./a.out

linklib: compilelib
\tgcc h1.o -L. -lx #-L. is necessary

compilelib: compile
\tmv h2.o libx.a

link: compile 
\tgcc h1.o h2.o

compile:
\tgcc -c h1.c
\tgcc -c h2.c

clean:
\trm *.o *.out
```

```
SRCS = h1.c h2.c
OBJS = $(SRCS:.c=.o)

all: link
\t./a.out

link: $(OBJS)
\t$(CC) $(OBJS)
```

Makefile: Variables
---

- variable represents strings of text
- standard variable: `CC`, `CFLAGS`, `LDFLAGS`
    - `LDFLAGS` library search path (`-L`)
    - `OBJS = $(SRCS:.c=.o)`: 
        - This incantation says that the object files  have the same name as the .c files, but with .o

Makefile: Dependency rules
---

- dependency rules: tells how to make a target based on changes to a list of certain files.
- If-this-then-that
    - dependency line: a trigger that says when to do something
    - command line: specifies what to do
    
<!-- 

Homework 4 - 2
---

1. In your ubuntu, open course website (https://github.com/syracuse-fullstacksecurity/cis342) (e.g. using Firefox) and hit the green "Clone or download" button to download all the files into a .zip file. Extract the zip file and cd into "marw4" directory. Type command "make"  to build and execute binary "a.out". Type command "ls" to list all files. Then type command "make clean" and command "ls" to show object files (with extension ".o") are gone. Submit a screenshot of your terminal.

2. We use the following command to compile `h2.c` as a library: `gcc -c h2.c -o liby.a`. Edit the file named "makefile" and add a new rule about the command. You may use `compilelib` as its label. And then type "make compilelib" to compile `h2.c` as a library. Submit the screenshot.

3. We can compile `h1.c` and link it to the library we just created using command `gcc -o a.out h1.c -L. -ly`. Add this command to the makefile with a new rule named `liblink`. What argument do you provide to "make" so that it can link the library liby. Provide a screenshot of making the program.

Advanced Makefile
---

```
source1:
source2:
xxx: source1 source2
	@echo $^ #source1 source2
	@echo $@ #xxx
	@echo $< #source1
```

```
PWD = $(shell pwd) #variable assigned by shell command
```

-->


GDB (Mar. W5)
===

References
---

- "Reviewing gcc, make, gdb, and Linux Editors", [[pdf](https://courses.cs.washington.edu/courses/cse333/11sp/sections/section01.pdf)]
- "Unix Programming Tools", [[link](http://cslibrary.stanford.edu/107/UnixProgrammingTools.pdf)]

A buggy program
---

```c
#include<stdio.h> //printf
int main(){
  int array_stack[] = {0,1,2};
  int sum = 0;
  for(int i=0; i<=3; i++){
    sum += array_stack[i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
```

Use gdb to find bug
---

- Installing gdb
- Run gdb: `gdb a.out`

Gdb command: control execution
---

- C execution model
- breakpoints
    - `break/b file:n|fn|file:fn`
    - `disable/enable/delete  bkpt`: `bkpt`=`file:n|fn|file:fn`
- stepping
    - `run/r`: run
    - `next/n`: next statement (step over a function call)
    - `continue/c`: continue till breakpoint

Gdb command: examine runtime
---

- examine runtime data
    - `print v`/`p/i v`: print as an integer
- examine code (with `gcc -g`)
    - `list/l`
- examine execution environment: e.g. stack (later)

Gdb functionality
---

| functionality | commands |
| --- | --- |
| breakpoints | `b`,`disable/enable/delete breakpoint`
| stepping | `r`,`s`,`n`,`c`,`finish`,`return`
| examine_data | `p/i v`,`display/undisplay`,`watch`,`set v=expr`
| examine_code | `list`
| examine_stack | `bt`,`where`,`info`,`up/down`,`frame`
| misc. | `editmode vi`, `b fn if expression`, `help`, disassembler, `shell cmd` 

Demo & exercise
---

- Exercise: Debugging the following program, upload the correct program to BB.

```c
#include<stdio.h> //printf
int main(){
  int a1[] = {0,1,2};
  int sum = 0;
  for(int i=0; i<=2; i++){
    sum += a1[i]/a1[2-i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
```

Examine stack
---

- C memory layout: stack
    - `backtrace`/`bt`,`where`
    - `up`,`down`,`frame #`
    - `info args/variables/locals`

C memory layout
---

```
   +--------------------+  
   |kernel              |
   +--------------------+  +
   |.text      (binary) |  |
   +--------------------+  fixed size
   |data       (const)  |  |
   +--------------------+  +
   |heap       (malloc) |  |
   +--------------------+  +
   |shared lib (binary) |  |
   +--------------------+  dynamic sized
   |user stack (local)  |  |
   +--------------------+  +
```

---

```c
#include<stdio.h> //printf
#include<stdlib.h> //malloc
//int array_data[] = {0,1,2};
int main(){
  int array_stack[] = {0,1,2};
  //int * array_heap = (int *)malloc(sizeof(int)*3);
  //array_heap[0] = 1;array_heap[1] = 2;array_heap[2] = 3;
  int sum = 0;
  for(int i=0; i<=3; i++){
    sum += array_stack[i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
```

<!--

Advanced commands
---

```
info proc mappings #print mem layout
info registers #print all register values
```

```
p/x var #print var in hex form
```

```
# Capturing printout before crash
./a.out > printout
...
call fflush(0)
```

-->


<!--

Section 2: C Programming Language
===

Program structure
---

- Demo:
    - 

```c
#include <stdio.h>
int main()
{
    printf( "Hello World!\n" );
    return 0;
}
```

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
```c
#include <stdio.h>	

int main()
{
    int age;
    printf( "Please enter your age" );
    scanf( "%d", &age );
    if ( age &lt; 100 ) {
        printf ("You are pretty young!\n" );
    }
    else if ( age == 100 ) {
        printf( "You are old\n" );       
    }
    else {
        printf( "You are really old\n" );
    }
  return 0;
}
```
- Exercise:
    - Write a program that gets an integer from user and prints "odd" or "even" based on the input.

Loops
---

- Demo:
```c
#include <stdio.h>

int main()
{
    int i;
    for ( i = 0; i &lt; 10; i++ ) {
        printf( "%d\n", i );
    }
    return 0;
}
```

```c
#include <stdio.h>

int main()
{ 
  int i = 0;
  while ( i < 10 ) {
      printf( "%d\n", x );
      x++;
  }
  return 0;
}
```

- Exercise:
    - Write a program that gets an integer from user and checks if it is a prime number or not
    - Write a progeam that prints all the prime numbers between 2 to 10000

Functions
---

- Demo:
```c
#include <stdio.h>

int power ( int x, int y );

int main()
{
    printf("%d",power(2,11));
}

int power (int x, int y)
{
  int i,out=1;
  for (i=0; i&lt;y; i++)
    out*=x;
  return out;
}
```
- Exercise:
    - Write a function that gets n as the input and calculates nth number in fibonacci sequence.
    - Write a function that gets n as the input and returns 1 if it is a prime number and returns 0 if it is not.

Arrays
---

- Demo:
```c
#include <stdio.h>

int main()
{
	int i,fib[10];
	fib[0]=1;
	fib[1]=1;
	for (i=2; i<10; i++)
		fib[i]=fib[i-1]+fib[i-2];
	for (i=0; i<10; i++)		
		printf("%d\n",fib[i]);
}
```

- Exercise:
    - Write a program to get an array with 10 integers from user and sort the array.




-->
