#include<stdio.h> //malloc
#include<stdlib.h> //malloc
int array_data[] = {0,1,2};
int main(){
  int array_stack[] = {0,1,2};
  int array_stack2[] = {4,5,6};
  int * array_heap = (int *)malloc(sizeof(int)*3);
  array_heap[0] = 1;array_heap[1] = 2;array_heap[2] = 3;

  printf("stack\t%p\n", array_stack);
  printf("stack2\t%p\n", array_stack2);
  printf("heap\t%p\n", array_heap);
  printf(".rodata\t%p\n", array_data);
  return 0;
}

