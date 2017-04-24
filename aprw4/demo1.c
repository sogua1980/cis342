struct movies_t {
  char * title;
  int year;
};
int main (){
  movies_t amovie;
  movies_t * pmovie;
  pmovie = &amovie;
  amovie.title = "the usual suspects";
  pmovie->year = 1995;
  return 0; 
}
