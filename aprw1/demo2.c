
#include<stdio.h> //printf
#include<string.h> //string
int main(){
  // constant 5 is encoded in assembly (.text)
  int i = 5;
  //string literal is in .rodata
  char * p = "hello world string";
  return 0;
}
