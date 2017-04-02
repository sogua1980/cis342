#include <stdio.h>
int fact(int x){
  return x*fact(x-1);
}
int main(){
  printf("%d\n",fact(5));
}

