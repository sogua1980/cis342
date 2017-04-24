#include<stdio.h>

struct movies_t {
  char * title;
  int year;
};
int main (){
  struct movies_t amovie;
  struct movies_t * pmovie;
  pmovie = &amovie;
  amovie.title = "the usual suspects";
  pmovie->year = 1995;
  printf("Movie %s is released in year %d\n", pmovie->title, pmovie->year);
  return 0; 
}
