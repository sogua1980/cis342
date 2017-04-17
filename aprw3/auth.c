#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int check_authentication(char *password) { 
  int auth_flag = 0;
  char password_buffer[16];
  strcpy(password_buffer, password);
  if(strcmp(password_buffer, "12345") == 0) auth_flag = 1;
  if(strcmp(password_buffer, "54321") == 0) auth_flag = 1;
  return auth_flag; 
}
int main(int argc, char *argv[]) { 
  if(argc < 2) exit(0); 
  if(check_authentication(argv[1])) { 
    printf("\nAccess Granted.\n"); 
  } else {
    printf("\nAccess Denied.\n");
  } 
}
