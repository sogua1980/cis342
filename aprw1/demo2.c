//string literal is in .text
// variable p1 is in .rodata
char * p1 = "foo";
int main(){
  // constant 5 is encoded in assembly (.text)
  int i = 5;
  //string literal is in .text
  // variable p2 is in stack
  char * p2 = "bar";
  return 0;
}
