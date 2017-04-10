#include<stdio.h>
int main(){
    int x = 4;
    // To complete the program below:
    int * p1 = &x;
    int * p2 = &x;
    * p1 = 5;
    printf("x=%d\n",*p2);
}
