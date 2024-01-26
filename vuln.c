#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 0x100
#define ADMIN_FLAG 0x4b4b4b4b 
#define USER_FLAG 0xffffffff

void prompt_terminal(char* buffer_input) {
  printf(">> ");
  gets(buffer_input);
}

int token_generator(long privilage_code) {
  if (privilage_code == ADMIN_FLAG) {
    printf("ADMIN_1337_L33T_ACC355\n");
    return 0;
  } else if (privilage_code == USER_FLAG) {
    printf("US3R_C0MM0N_K3Y_ACC3SS\n");
    return 1;
  } else {
    printf("No Key Access Granted\n");
    printf("privilage_code == 0x%llx\n", privilage_code);
    printf("privilage_code != 0x%llx\n", ADMIN_FLAG);
    return -1;
  }
}

void shell_access(int identifier) {
  if ( identifier == 0 ) {
    while (true) {
      size_t num_chars = 255;
      char *terminal_admin_buffer = (char *)malloc(num_chars + 1);
      gets(terminal_admin_buffer);
      printf("\n%s\n", terminal_admin_buffer);
      free(terminal_admin_buffer);
    } 
  } else if ( identifier == 1 ) {
    while (true) {
      size_t num_chars = 255;
      char *terminal_user_space = (char *)malloc(num_chars + 1);
      gets(terminal_user_space);
      printf("\n%s\n", terminal_user_space);
      free(terminal_user_space);
    }
  }
}

int main(void) {
  long user_privilage = 0x10000000;
  char password[BUFFER_SIZE];

  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);

  prompt_terminal(password);
  
  int identifier = token_generator(user_privilage);
  printf("%d", identifier);

  shell_access(identifier);
  return 0;
}
