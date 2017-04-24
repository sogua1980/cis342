void print() {
  char * message = "hello world\n";
  asm ( "mov $12, %%rdx\n\t"
      "mov %0, %%rcx\n\t"
      "mov $0, %%rbx\n\t"
      "mov $4, %%rax\n\t"
      "int $0x80 \n\t"
      ::"r"(message):"rdx","rcx","rbx");
}
int main(){
   print();
}
