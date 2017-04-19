#include<stdio.h>
int main(int argc, char *argv[]) { 
  if(argc < 2) return 1;
  printf("arg is %s\n", argv[1]); //%s for char array
}
