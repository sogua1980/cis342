#include<stdio.h> //printf
#include<stdlib.h> //malloc
//int array_data[] = {1,2,3};
int main(){
  int array_stack[] = {1,2,3};
  //int * array_heap = (int *)malloc(sizeof(int)*3);
  //array_heap[0] = 1;array_heap[1] = 2;array_heap[2] = 3;
  int sum = 0;
  for(int i=0; i<=3; i++){
    sum += array_stack[i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
