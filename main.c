#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 0x100

struct User {
  char username[BUFFER_SIZE];
  char password[BUFFER_SIZE];
  int isAdmin;
};

struct User userArray[] = {
  {"maverick", "cruise_ship", 1},
  {"hammond", "hackerman", 0},
  {"thomas", "whitehat", 1},
  {"steve", "pixydust_are_steps", 0},
  {"patil", "bravo_charlie", 1},
  {"wozniak", "nerd_for_life", 0},
};

char* prompt_terminal(char* input) {
  printf(">> ");
  gets(input);
  return input;
}

int authentication(const struct User users[], int num_users, const char* username, const char* password) {
  for (int i = 0; i < num_users; ++i) {
    if (strcmp(users[i].username, username) == 0) {
      if (strcmp(users[i].password, password) == 0) {
        printf("Privilage: %d\n", users[i].isAdmin);
        return 0;
      } else {
        return 1;
      } 
    }
  }
  return -1;
}

int check_admin_privilages(const struct User users[], int num_users, const char* username) {
  for (int i = 0; i < num_users; ++i) {
      if (strcmp(users[i].username, username) == 0) {
          if (users[i].isAdmin == 1) {
              return 0;
          } else {
              return 1;
          }
      }
  }
  return -1;  
}

char* return_token(int privilage_code, char* username, char* password, int num_users) {
  privilage_code = check_admin_privilages(userArray, num_users, username);
  
  if (privilage_code == 0) {
    return "ADMIN_1337_4444_ACC355_GR4AN7D";
  } else if (privilage_code == 1) {
    return "USER_1111_L1M1T_CH3CK_K3Y";
  } else {
    return "ERROR - No User Entry Found";
  }
} 

int main() {
  static char username[BUFFER_SIZE];
  static char password[BUFFER_SIZE];

  printf("Enter the Username\n");
  prompt_terminal(username); 
  printf("Enter the Password\n");
  prompt_terminal(password);
  
  printf("Username: %s\n", username);
  printf("Password: %s\n", password);
  
  int num_users = sizeof(userArray) / sizeof(userArray[0]);
  int auth_state = -1;
  int privilage_code = -1;

  auth_state = authentication(userArray, num_users, username, password);
  printf("Auth state: %d\n", auth_state);

  if (auth_state == 1) {
    printf("User: %s found, password incorrect\n", username);
    return 0;
  } else if (auth_state == -1) {
    printf("User: %s not found\n", username);
    return 0;
  } 
 
  char* token_key = return_token(privilage_code, username, password, num_users);
  printf("Token Key: %s\n", token_key);

  return 0;
}
