#include<stdio.h>
#include<stdlib.h>
// global variable x
int x = 1;
int main(){
  // local variable y
  int y = 2;
  // dynamically-allocated variable pz
  int * pz = malloc(2*sizeof(int));
  // static local variable t
  static int t = 4;
  printf("x at %p\ny at %p\npz to %p\nt at %p\n", &x, &y, pz, &t);
  return 0;
}
