% Lecture notes in CIS342 
% Yuzhe Tang, Amin Fallahi
% Spring, 2017



Section 2: Programming in C/C++ 
===

gcc & make (Mar. w4)
===

References
---

- "Unix Programming Tools", [[link](cslibrary.stanford.edu/107/UnixProgrammingTools.pdf)]
- Computer Systems: A Programmer's Perspective, Randal E. Bryant and David R. O'Hallaron, Chapter 1, [[online pdf](http://csapp.cs.cmu.edu/2e/ch1-preview.pdf)]

Compilation overview
---

- Two steps of compilation:
    - *compiling*: text `.c` file to  reocatable `.o` (object) file
    - *linking*: multiple relocatable `.o` files to one executable `.o` file
        - *symbol*: reference to link construct (declaration) in one `.o` file to construct (definition) in another `.o` file

![linker](/Users/tristartom/workspace/teaching/cis342/cis342/images/link.png)


C: basics
---

```c
#include <stdio.h> //preprocessor
int y = 3; //global var. (def. & init.)
//extern int y; //global var. (dec.)
int main() //function (def.)
{
    int x = 0; //local var. (def. & init.), literal, 
    printf( "y=%d\n",y); //function (invocation)
    return 0;
}
```

- life of a C construct
    - declaration: `extern int x;`, `void foo();`
    - definition: `int x;`, `void foo(){}`
    - initialization: `int x = 6;`
    - assignment: `x=1;`
    - destroy

Gcc: Flags
---

- `-c` for compile, `-o` for output; demo
- `-Wall`, w for warning; demo 
- `-I` for `#include`; demo
    - header file (storing declarations)
- `-Ldir`/`-lmylib` for library to link
    - search library for unsolved sumbols (functions, global variables) when linking
- `-g` for debug (later)


make
---

```
all:
	gcc -c h1.c
	gcc -c h2.c
	gcc h1.o h2.o
	./a.out
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
