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

